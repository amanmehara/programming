<?php
// API access key from Google API's Console
define( 'API_ACCESS_KEY', 'Your API key Goes here' );


$items=array();
$file = fopen("book1.csv","r"); /* put name of your csv file which contains all the keys*/
$i=0;

while(!feof($file))
  {
$ids=(fgetcsv($file)); 
//print_r($ids[0]);
$items[$i]=$ids[0];
$i++;
  }

fclose($file);
print_r($items);


$registrationIds =$items;
$msg = array
(
	'message' 	=> 'Testing he haha haa hahah haa haha',
	'title'		=> 'Push Notification',
	'subtitle'	=> 'This is a subtitle. subtitle',
	'tickerText'	=> 'Ticker text here...Ticker text here...Ticker text here',
	'vibrate'	=> 1,
	'sound'		=> 1,
	'largeIcon'	=> 'large_icon',
	'smallIcon'	=> 'small_icon'
	//'type' => 'track-uninstall'
	
);
$fields = array
(
	'registration_ids' 	=> $registrationIds,
	'data'			=> $msg
);
 
$headers = array
(
	'Authorization: key=' . API_ACCESS_KEY,
	'Content-Type: application/json'
);
 
$ch = curl_init();
curl_setopt( $ch,CURLOPT_URL, 'https://android.googleapis.com/gcm/send' );
curl_setopt( $ch,CURLOPT_POST, true );
curl_setopt( $ch,CURLOPT_HTTPHEADER, $headers );
curl_setopt( $ch,CURLOPT_RETURNTRANSFER, true );
curl_setopt( $ch,CURLOPT_SSL_VERIFYPEER, false );
curl_setopt( $ch,CURLOPT_POSTFIELDS, json_encode( $fields ) );
$result = curl_exec($ch );

echo $result;

file_put_contents("output1.txt",$result); //output file name to put the result
/*
$file1 = fopen("output.csv","w");

foreach ($result as $line)
  {
  fputcsv($file1,explode(',',$line));
  }

fclose($file1); 
*/
?>

