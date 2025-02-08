#!/bin/bash

files=$(git diff --diff-filter=d --name-only origin/$GITHUB_BASE_REF origin/$GITHUB_HEAD_REF lyah)
error_files=()

for file in $files; do
	if [[ $(head -n 2 $file) != "$HEADER" ]]; then
		error_files+=($file)
	fi
done

if [[ ${#error_files[@]} -gt 0 ]]; then
	echo "The following file(s) don't start with a copyright license header." >> $GITHUB_STEP_SUMMARY

	for file in "${error_files[@]}"; do
		echo "- [$file]($GITHUB_TREE_URL/$file)" >> $GITHUB_STEP_SUMMARY
	done

	exit 1
fi