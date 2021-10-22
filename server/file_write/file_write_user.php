<?php
$data;
$array;
$data_name = array('function','sec', 'interval', 'r', 'g', 'b','r2','g2','b2');

$data_name_size = count($data_name);





    


function file_open_write($data, $file)
{
    $fp = fopen($file, 'ab');

    if ($fp) {
        if (flock($fp, LOCK_EX)) {
            if (fwrite($fp,  $data . ",") === FALSE) {
                //  print('ファイル書き込みに失敗しました<br>');
            } else {
                //  print($data.'をファイルに書き込みました<br>');

            }

            flock($fp, LOCK_UN);
        } else {
            print('ファイルロックに失敗しました<br>');
        }
    }

    $flag = fclose($fp);

    if ($flag) {

        print('無事クローズしました<br>');
    } else {
        print('クローズに失敗しました<br>');
    }
}

$url = "http://54.248.37.203/file_write/light/json/scene_playlist.json";
$json = file_get_contents($url);
$decoded_json = json_decode($json, true);

// $fp=fopen("scene_playlist.json","r");
// $scene_playlist=fgetcsv($fp);
// fclose("scene_playlist.json");
//var_dump($scene_playlist);
//$encoded_scene_playlist = json_encode($scene_playlist, JSON_UNESCAPED_UNICODE);
//$decoded_scene_playlist = json_decode($scene_playlist, true);
//var_dump($decoded_scene_playlist);
$decoded_json_size = count($decoded_json);
//var_dump($decoded_json[0]);

//var_dump($decoded_scene_playlist[0]);//[$data_name["sec"]]);
$data=$decoded_json[0]["sec"];
 //for ($i=0;$i<5;$i++){
     //var_dump($decoded_json[0]["sec"]);//[$data_name["name"]]);
     //print($data);
 //}

 $fp = fopen("csv/directing_user_data.csv",'wb');
        flock($fp, LOCK_EX);
        ftruncate($fp,0);
        flock($fp, LOCK_UN);
        fclose($fp);

for ($i=0;$i<$decoded_json_size;$i++){
    $decoded_json_value_size =count($decoded_json[$i]);
    for ($j=0;$j<$decoded_json_value_size;$j++){
        print($decoded_json[$i][$data_name[$j]]);
        file_open_write($decoded_json[$i][$data_name[$j]], "csv/directing_user_data.csv");
    }
}
