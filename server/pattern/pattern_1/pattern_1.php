<?php
$data;

function file_open_write($data, $file)
{
    $fp = fopen($file, 'w+b');

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
    //print($data);
    if ($data != null) {
        file_open_write($data, "csv/function_data.csv");
    }
}

$fp = fopen("csv/function_data.csv", "r");
$fustion_data = fgetcsv($fp);
fclose("csv/function_data.csv");


?>

<!DOCTYPE html>
<html lang="ja">

<head>
    <meta charset="utf-8">
    <title>タイトル</title>
    <meta name="description" content="ディスクリプションを入力">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="pattern_1.css">

    <script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js' id='jquery-js'></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
    <!-- <script src="pattern_1/pattern_1.js"></script> -->
    <script src="pattern_1.js"></script>



</head>

<body>



    <div class="box">
        <h2><span class="badge-warning">00</span></h2>
    </div>
    <div class="box2">
        <h2><span class="badge-warning2">0.00</span></h2>
    </div>
    <div class="box3">
        <h2><span class="badge-warning3">000</span></h2>
    </div>
    <div class="box4">
        <h2><span class="badge-warning4">000</span></h2>
    </div>
    <div class="box5">
        <h2><span class="badge-warning5">000</span></h2>
    </div>

    <div class="box6">
        <h2><span class="badge-warning6"><?php echo (int)$fustion_data[0]; ?></span></h2>
    </div>


    <input id="slider" class="range-style" type="range" value="5" min="0" max="60" step="1" />
    <input id="slider2" class="range-style2" type="range" value="0.05" min="0.01" max="1" step="0.01" />
    <input id="slider3" class="range-style3" type="range" value="5" min="0" max="255" step="1" />
    <input id="slider4" class="range-style4" type="range" value="5" min="0" max="255" step="1" />
    <input id="slider5" class="range-style5" type="range" value="5" min="0" max="255" step="1" />
    <div id="text-button" class="button" onclick="clickDisplayAlert()">Confirm</div>





 

</body>



</html>