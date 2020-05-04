<?php

$maxdB = $_POST['maxdB'];
$peaks = $_POST['peaks'];
$today = date("Y-m-d H:i:s");
$record = $today . ", Maximum decibel is: " . $maxdB . ", Number of peaks are: " . $peaks . "\n";

$file = "testsound.log";
if(file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);
echo "From e1900324, An Cao\n";

?>
