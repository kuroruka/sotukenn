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
}

$fp = fopen('csv/directing_live_penlight_data.csv','wb');
        flock($fp, LOCK_EX);
        ftruncate($fp,0);
        flock($fp, LOCK_UN);
        fclose($fp);

for ($i = 0; $i < $data_name_size; $i++) {
    if ($data[$data_name[$i]] != null) {
        file_open_write($data[$data_name[$i]], "csv/directing_live_penlight_data.csv");
    }
}
