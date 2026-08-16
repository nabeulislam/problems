#!/usr/bin/env bash
set -euo pipefail

folder="${1:-}"
output_zip="${2:-}"

if [[ -z "$folder" || -z "$output_zip" ]]; then
  echo "Usage: $0 <folder> <output.zip>"
  exit 1
fi

if [[ ! -d "$folder" ]]; then
  echo "Error: folder does not exist: $folder"
  exit 1
fi

# Zip only .in files directly inside the given folder, not subfolders.
find "$folder" -maxdepth 1 -type f -name '*.in' -print0 | \
  xargs -0 zip -j "$output_zip"