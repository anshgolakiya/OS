echo "Executable files: "
find . -type f -executable

echo "Directories:"
find . -type d

echo "Zero sized files: "
find . -type f -size 0
