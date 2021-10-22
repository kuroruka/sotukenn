<?php



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



if (isset($_POST['data'])) {

    $data = $_POST['data'];

    
    $url = "json/scene_playlist_penlight.json";
    $json = file_get_contents($url);
    $decoded_json2 = json_decode($json, true);

    var_dump($decoded_json2); 

    if ($decoded_json2 == null) {
        
        
        $encode_json = json_encode($data, JSON_UNESCAPED_UNICODE);


        $fp = fopen('json/scene_playlist_penlight.json', 'w+b');
        fwrite($fp, $encode_json);
        fclose($fp);

        $fp = fopen('csv/playlist_number_penlight.csv', 'w+b');
        fwrite($fp, 1);
        fclose($fp); 

    } else {
        $array = array_merge($decoded_json2, $data);

        $merge_json = json_encode($array, JSON_UNESCAPED_UNICODE);

        

        

        $fp = fopen('json/scene_playlist_penlight.json', 'w+b');
        fwrite($fp, $merge_json);
        fclose($fp);

        $fp = fopen('csv/playlist_number_penlight.csv', 'w+b');
        fwrite($fp, count($array));
        fclose($fp);
    }
}
