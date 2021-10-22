<?php
$data;
$array;
$data_name = array('function','number_time', 'time_down','time_up','angle_down','angle_up','microsecond_down','microsecond_up');

$data_name_size = count($data_name);





 


function file_open_write($data, $file)
{
    $fp = fopen($file, 'ab');

    if ($fp) {
        if (flock($fp, LOCK_EX)) {
            if (fwrite($fp,  $data . ",") === FALSE) {
                  print('ファイル書き込みに失敗しました<br>');
            } else {
                  //print($data.'をファイルに書き込みました<br>');

            }

            flock($fp, LOCK_UN);
        } else {
            //print('ファイルロックに失敗しました<br>');
        }
    }

    $flag = fclose($fp);

    if ($flag) {

        print('無事クローズしました<br>');
    } else {
        print('クローズに失敗しました<br>');
    }
}

$url = "http://54.248.37.203/file_write/penlight/json/scene_playlist_penlight.json";
$json = file_get_contents($url);
$decoded_json = json_decode($json, true);


$decoded_json_size = count($decoded_json);


//var_dump($decoded_scene_playlist[0]);//[$data_name["sec"]]);
//print($decoded_json["number_time"]);

 //for ($i=0;$i<5;$i++){
     //var_dump($decoded_json[0]["sec"]);//[$data_name["name"]]);
     //print($data);
 //}

 $fp = fopen("csv/directing_user_penlight_data.csv",'wb');
        flock($fp, LOCK_EX);
        ftruncate($fp,0);
        flock($fp, LOCK_UN);
        fclose($fp);

for ($i=0;$i<$decoded_json_size;$i++){
//for ($i=0;$i<2;$i++){
    $decoded_json_value_size =count($decoded_json[$i]);
    //print($i."\n");
    for ($j=0;$j<$decoded_json_value_size;$j++){
        print($decoded_json[$i][$data_name[$j]]);
        file_open_write($decoded_json[$i][$data_name[$j]], "csv/directing_user_penlight_data.csv");
    }
}
