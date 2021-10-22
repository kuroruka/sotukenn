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
// $url = "json/scene_playlist.json";
// $json = file_get_contents($url);
// $decoded_json2 = json_decode($json, true);
// $str = $decoded_json2;
// var_dump($str); 



if (isset($_POST['data'])) {

    $data = $_POST['data'];


    //$url = "json/scene_playlist.json";
    $url = "http://54.248.37.203/file_write/light/json/scene_playlist.json";
    $json = file_get_contents($url);
    $decoded_json2 = json_decode($json, true);
    
    
    // $decoded_json3 = json_encode($decoded_json2, JSON_UNESCAPED_UNICODE);



    // $fp = fopen('json/scene_playlist.json', 'ab'); 
    // fwrite($fp, $decoded_json3);
    // fclose($fp);

    // $fp = fopen('json/scene_playlist.json', 'w+b');
    // fwrite($fp, $decoded_json2); 
    // fclose($fp);

    if ($decoded_json2 == null) {
        $encode_json = json_encode($data, JSON_UNESCAPED_UNICODE);

        $fp = fopen('json/scene_playlist.json', 'w+b');
        fwrite($fp, $encode_json);
        fclose($fp);

        $fp = fopen('csv/playlist_number.csv', 'w+b');
        fwrite($fp, 1);
        fclose($fp);
    } else {


        $array = array_merge($decoded_json2, $data);

        

        $merge_json = json_encode($array, JSON_UNESCAPED_UNICODE);

        //$merge_json = json_encode($decoded_json2, JSON_UNESCAPED_UNICODE);

        
        //file_put_contents('json/scene_playlist.json',$merge_json);

        //count($array);

        //$encode_json = json_encode($data, JSON_UNESCAPED_UNICODE);
        $fp = fopen('json/scene_playlist.json', 'w+b');
        fwrite($fp,$merge_json);
        fclose($fp);

        $fp = fopen('csv/playlist_number.csv', 'w+b');
        fwrite($fp,count($array));
        fclose($fp);
     }
}
