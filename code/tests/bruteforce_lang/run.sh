#!/bin/bash

file_path="test_file.txt"
search_string="chercher"

echo "Running Python script..."
start=$(date +%s.%N)
python3 search_in_file.py "$file_path" "$search_string"
end=$(date +%s.%N)
python_time=$(echo "$end - $start" | bc)
echo "Python execution time: $python_time seconds"

echo "Running Node.js script..."
start=$(date +%s.%N)
node search_in_file.js "$file_path" "$search_string"
end=$(date +%s.%N)
node_time=$(echo "$end - $start" | bc)
echo "Node.js execution time: $node_time seconds"

echo "Running C script..."
gcc -o search_in_file search_in_file.c
start=$(date +%s.%N)
./search_in_file "$file_path" "$search_string"
end=$(date +%s.%N)
c_time=$(echo "$end - $start" | bc)
echo "C execution time: $c_time seconds"

echo "Execution times:"
echo "Python: $python_time seconds"
echo "Node.js: $node_time seconds"
echo "C: $c_time seconds"
