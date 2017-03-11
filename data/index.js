
  var keyword = "balcony garden";
  var screenInit = 0;
	var newVari = 0;
	var oldVari = 10;
  var textS;
  var curTemp = 20;
  var curInterval = 60;
  var curSensor = 0;
  var curWatering = false;
  var curStarted = false;
  var last = 0;

//var url = 'http://192.168.20.10'
//var url = 'http://wonderWater.local/';
var url = '';



function setup() {
  createCanvas(640, 480);

  heading = createP("Main Page");
  heading.position(20, 5);
  heading.class("h1");

  waterButton = createButton('START/STOP');
  waterButton.position(150, 85);
  waterButton.id('start');
  document.getElementById('start').onclick = function(e)
  {
    sendButton("Start");
  };
  //waterButton = createButton('WATER');
  //waterButton.position(250, 85);
  //waterButton.mousePressed(water);

  waterButton = createButton('WATER NOW');
  waterButton.position(350, 85);
  waterButton.id('water');
  document.getElementById('water').onclick = function(e)
  {
    sendButton("Water");
  };

  flashButton = createButton('SETTINGS');
  flashButton.position(350, 165);
  flashButton.id('settings');
  document.getElementById('settings').onclick = function(e)
  {
    linkPage("change.html");
  };

}
/*
function water() {
  var xhr = new XMLHttpRequest();
  xhr.open('GET', url +"buttonPage/ON", true);
  xhr.send();
}
*/


function getSensor(){
   console.log("get sensor value");
   var address = url + "sensor";
   loadJSON(address, loadSensor);
}

function loadSensor(newSensor){
//Get the loaded JSON data
  console.log("commencing loading");
  console.log(newSensor);
  curSensor = newSensor.sensor;
  console.log("loaded");

}
function getButtons(){
console.log("get buttons");

   var address = url + "buttons";
   loadJSON(address, loadButtons);
}

function loadButtons(newButtons){
//Get the loaded JSON data
console.log("commencing loading");
  console.log(newButtons);
  curWatering = newButtons.watering;
  curStarted = newButtons.started;
  console.log("loaded");

}

function sendButton(mode) {
  var xhr = new XMLHttpRequest();
  if((mode == water) && (!started)){
  alert("Watering system must be turned on first");
}
else{
  xhr.open('GET', url +"buttons/save?Button=" + mode, true);
  xhr.send();
}
getButtons();
}



function linkPage(page){
 var address = url + page;
 window.location.href = address;
}


function draw(){
  clear();
  if(millis()>last +3000){
    getSensor();
    getButtons();
    last = millis();
  }
fill(0);
textSize(30);
text(curSensor, 200,300);

if(curWatering){
  fill(0,255,0);
}
else{
  fill(255,0,0);
}
 rect(400,200,50,50);

}



    $(document).ready(function(){

        $.getJSON("http://api.flickr.com/services/feeds/photos_public.gne?jsoncallback=?",
        {
            tags: keyword,
            tagmode: "any",
            format: "json"
        },
        function(data) {
            var rnd = Math.floor(Math.random() * data.items.length);

            var image_src = data.items[rnd]['media']['m'].replace("_m", "_b");

           $('body').css('background-image', "url('" + image_src + "')");

        });

    });
