let value_1 = 0;
let value_2 = 0;
let value_3 = 0;
let value_4 = 0;
let value_5 = 0;
var function_data;


function Ajax(value,value2,value3,value4,value5,path){
    
    var s = document.getElementsByClassName('badge-warning6')[0].textContent;
        function_data = s.trim();
    
    var data =  {
        'function': function_data,
        'sec': value,
        'interval': value2 * 100000,
        'r': value3,
        'g': value4,
        'b': value5

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

        Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/file_write_live.php');

    });

    var hoge2 = document.getElementById("slider2");
    // 選択した際のイベント取得
    hoge2.addEventListener('input', (e) => {
        value_2 = hoge2.value ;
        console.log(value_2);
        document.getElementsByClassName('badge-warning2')[0].textContent = hoge2.value ;

        Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/file_write_live.php');

        
    });

    var hoge3 = document.getElementById("slider3");
    // 選択した際のイベント取得
    hoge3.addEventListener('input', (e) => {
        value_3 = hoge3.value;
        document.getElementsByClassName('badge-warning3')[0].textContent = hoge3.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/file_write_live.php');

        
    });

    var hoge4 = document.getElementById("slider4");
    // 選択した際のイベント取得
    hoge4.addEventListener('input', (e) => {
        value_4 = hoge4.value;
        document.getElementsByClassName('badge-warning4')[0].textContent = hoge4.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/file_write_live.php');

        
    });
    var hoge5 = document.getElementById("slider5");
    // 選択した際のイベント取得
    hoge5.addEventListener('input', (e) => {
        value_5 = hoge5.value;
        document.getElementsByClassName('badge-warning5')[0].textContent = hoge5.value;

        Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/file_write_live.php');

        
    });

}

function clickDisplayAlert() {

    Ajax(value_1,value_2,value_3,value_4,value_5,'http://54.248.37.203/file_write/json_file_write.php')

    window.location.href = 'http://54.248.37.203/index.html';

}
