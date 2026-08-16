#!/bin/bash

set -euo pipefail

# Default to checking the tests directory next to this script.
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
root_dir="${1:-${script_dir}/tests}"

if [[ ! -d "${root_dir}" ]]; then
    echo "Error: '${root_dir}' is not a directory." >&2
    exit 2
fi

declare -A hash_to_files

while IFS= read -r -d '' file_path; do
    file_hash="$(sha256sum "${file_path}" | awk '{print $1}')"
    if [[ -n "${hash_to_files["${file_hash}"]-}" ]]; then
        hash_to_files["${file_hash}"]+=$'\n'"${file_path}"
    else
        hash_to_files["${file_hash}"]="${file_path}"
    fi
done < <(find "${root_dir}" -type f -name '*.in' -print0)

found_duplicate="false"

for file_hash in "${!hash_to_files[@]}"; do
    mapfile -t files < <(printf '%s\n' "${hash_to_files["${file_hash}"]}")
    if (( ${#files[@]} > 1 )); then
        if [[ "${found_duplicate}" == "false" ]]; then
            echo "Duplicate .in data files:"
            found_duplicate="true"
        fi
        echo "- sha256: ${file_hash}"
        for file_path in "${files[@]}"; do
            echo "  ${file_path}"
        done
    fi
done

if [[ "${found_duplicate}" == "true" ]]; then
    exit 1
fi

echo "No duplicate .in data files found."
