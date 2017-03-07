
  var keyword = "balcony garden";
  var screenInit = 0;
	var newVari = 0;
	var oldVari = 10;
  var textS;
  var curTemp = 20;
  var curInterval = 60;
  var curSensor = 0;
  var watering = false;
  var started = false;
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
  waterButton.mousePressed(start);

  //waterButton = createButton('WATER');
  //waterButton.position(250, 85);
  //waterButton.mousePressed(water);

  waterButton = createButton('WATER NOW');
  waterButton.position(350, 85);
  waterButton.mousePressed(water);

  flashButton = createButton('SETTINGS');
  flashButton.position(350, 165);
  flashButton.id('settings');
  document.getElementById('settings').onclick = function(e) {linkPage("change.html");
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
  watering = newButtons.watering;
  started = newButtons.started;
  console.log("loaded");

}

function water() {
  var xhr = new XMLHttpRequest();
  if(started){
  if(!watering){watering=true;}
  else{watering = false;}
  xhr.open('GET', url +"buttons/save?Water=" + watering, true);
  xhr.send();
}
else{
  alert("Watering system must be turned on first");
}
}

function start() {
  var xhr = new XMLHttpRequest();
  if(!started){started=true;}
  else{started = false;
  watering = false;}
  xhr.open('GET', url +"buttons/save?Start=" + started, true);
  xhr.send();
}


function linkPage(page){
 var address = url + page;
 window.location.href = address;
}


function draw(){
  clear();
  if(millis()>last +3000){
    getSensor();
    //getButtons();
    last = millis();
  }
fill(0);
textSize(30);
text(curSensor, 200,300);

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
