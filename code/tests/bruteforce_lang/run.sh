#!/bin/bash

file_path="./rockyou.txt"
search_string="chercher"

echo "Running python script..."
start=$(date +%s.%N)
python3 main.py "$file_path" "$search_string"
end=$(date +%s.%N)
python_time=$(echo "$end - $start" | bc)
echo "Python execution time: $python_time seconds"

# echo "Running node.ts script..."
# start=$(date +%s.%N)
# ts-node main.ts "$file_path" "$search_string"
# end=$(date +%s.%N)
# node_time=$(echo "$end - $start" | bc)
# echo "ndoe.ts execution time: $node_time seconds"

echo "Running C script..."
gcc -o search_in_file main.c
start=$(date +%s.%N)
./search_in_file "$file_path" "$search_string"
end=$(date +%s.%N)
c_time=$(echo "$end - $start" | bc)
echo "C execution time: $c_time seconds"

echo "Execution times:"
echo "Python: $python_time seconds"
echo "Node.js: $node_time seconds"
echo "C: $c_time seconds"
