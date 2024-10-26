$filePath = "./rockyou.txt"
$searchString = "chercher"

Write-Output "Running python script..."
$startTime = Get-Date
python .\main.py $filePath $searchString
$endTime = Get-Date
$pythonTime = ($endTime - $startTime).TotalSeconds
Write-Output "python execution time: $pythonTime seconds"

Write-Output "`nRunning node.ts script..."
$startTime = Get-Date
ts-node .\main.ts $filePath $searchString
$endTime = Get-Date
$nodeTime = ($endTime - $startTime).TotalSeconds
Write-Output "node.ts execution time: $nodeTime seconds"

Write-Output "`nRunning C script..."
gcc .\main.c -o search_in_file
$startTime = Get-Date
.\search_in_file.exe $filePath $searchString
$endTime = Get-Date
$cTime = ($endTime - $startTime).TotalSeconds
Write-Output "C execution time: $cTime seconds"

Write-Output "`nExecution times:"
Write-Output "python: $pythonTime seconds"
Write-Output "node.ts: $nodeTime seconds"
Write-Output "C: $cTime seconds"
