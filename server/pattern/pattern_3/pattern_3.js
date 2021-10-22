let value_1 = 0;
let value_2 = 0;
let value_3 = 0;
let value_4 = 0;
let value_5 = 0;
let value_6 = 0;
let value_7 = 0;  
var function_data;

function Ajax(value,value2,value3,value4,value5,value6,value7,path){
    
    var s = document.getElementsByClassName('badge-warning9')[0].textContent;
        function_data = s.trim();
    
    var data =  {
        'function': function_data,
        'number_time': value,
        'time_down': value2 ,
        'time_up': value3,
        'angle_down': value4,
        'angle_up': value5,
        'microsecond_down': value6,
        'microsecond_up': value7

    };


    console.log(data);
    $.ajax({
        type: 'POST', //　POSTかGET  
        url: path, //　送り先
        data: {
            'data': data
        }, //　渡したいデータ
        dataType: 'json', //　データ形式を指定
        scriptCharset: 'UTF-8' //　文字コードを指定
    })
}



window.onload = function () {

    var hoge = document.getElementById("slider");
    // 選択した際のイベント取得
    hoge.addEventListener('input', (e) => {
        value_1 = hoge.value;
        document.getElementsByClassName('badge-warning')[0].textContent = hoge.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');

    });

    var hoge2 = document.getElementById("slider2");
    // 選択した際のイベント取得
    hoge2.addEventListener('input', (e) => {
        value_2 = hoge2.value ;
        console.log(value_2);
        document.getElementsByClassName('badge-warning2')[0].textContent = hoge2.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');
    });

    var hoge3 = document.getElementById("slider3");
    // 選択した際のイベント取得
    hoge3.addEventListener('input', (e) => {
        value_3 = hoge3.value;
        document.getElementsByClassName('badge-warning3')[0].textContent = hoge3.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');
    });

    var hoge4 = document.getElementById("slider4");
    // 選択した際のイベント取得
    hoge4.addEventListener('input', (e) => {
        value_4 = hoge4.value;
        document.getElementsByClassName('badge-warning4')[0].textContent = hoge4.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');

    });
    var hoge5 = document.getElementById("slider5");
    // 選択した際のイベント取得
    hoge5.addEventListener('input', (e) => {
        value_5 = hoge5.value;
        document.getElementsByClassName('badge-warning5')[0].textContent = hoge5.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');
    });

    var hoge6 = document.getElementById("slider6");
    // 選択した際のイベント取得
    hoge6.addEventListener('input', (e) => {
        value_6 = hoge6.value;
        document.getElementsByClassName('badge-warning6')[0].textContent = hoge6.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');
    });

    var hoge7 = document.getElementById("slider7");
    // 選択した際のイベント取得
    hoge7.addEventListener('input', (e) => {
        value_7 = hoge7.value;
        document.getElementsByClassName('badge-warning7')[0].textContent = hoge7.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,value_6,value_7,'http://54.248.37.203/file_write/penlight/json_file_write_live_penlight.php');
    });

    

}

function clickDisplayAlert() {
   
    

    var s = document.getElementsByClassName('badge-warning9')[0].textContent;
        function_data = s.trim();
    
    var data =  [{
        'function': function_data,
        'number_time': value_1,
        'time_down': value_2 ,
        'time_up': value_3,
        'angle_down': value_4,
        'angle_up': value_5,
        'microsecond_down': value_6,
        'microsecond_up': value_7

    }];


    console.log(data);
    $.ajax({
        type: 'POST', //　POSTかGET  
        url: 'http://54.248.37.203/file_write/penlight/json_file_write_penlight.php', //　送り先
        data: {
            'data': data
        }, //　渡したいデータ
        dataType: 'json', //　データ形式を指定
        scriptCharset: 'UTF-8' //　文字コードを指定
    })

    window.location.href = 'http://54.248.37.203/index.html';

}
