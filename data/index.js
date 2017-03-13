
  var keyword = "balcony garden";
  var screenInit = 0;
	var newVari = 0;
	var oldVari = 10;
  var textS;
  var curTemp;
  var curInterval;
  var curSensor = 0;
  var curWatering ;
  var curStarted;
  var last = 0;

//var url = 'http://192.168.20.10'
//var url = 'http://wonderWater.local/';
  var url = '';



function setup() {
  createCanvas(640, 480);
  getButtons();
  getSensor();

  heading = createP("wonderwater");
  heading.position(20, 0);
  heading.class("h1");

  startButton = createButton('START/STOP SYSTEM');
  startButton.position(20, 95);
  startButton.id('start');
  document.getElementById('start').onclick = function(e)
  {
    sendButton("Start");
  };

  waterButton = createButton('WATER NOW');
  waterButton.position(220, 95);
  waterButton.id('water');
  document.getElementById('water').onclick = function(e)
  {
    if(curStarted){
    sendButton("Water");
  }
  else{
    alert("system must be started first");
  }
  };

  flashButton = createButton('SETTINGS');
  flashButton.position(20, 450);
  flashButton.id('settings');
  document.getElementById('settings').onclick = function(e)
  {
    window.location.href = "change.html";
  };

}



function getSensor(){
   console.log("get sensor value");
   loadJSON("sensor", loadSensor);
}

function loadSensor(newSensor){
//Get the loaded JSON data
  console.log(newSensor);
  curSensor = newSensor.sensor;
  console.log("loaded sensor json");
}

function getButtons(){
    console.log("get buttons");
   //var address = url + "buttons";
   loadJSON("buttons", loadButtons);
}

function loadButtons(newButtons){
//Get the loaded JSON data
  console.log(newButtons);
  curWatering = newButtons.watering;
  curStarted = newButtons.operating;
  console.log("loaded buttons");

}

function sendButton(mode) {
  var xhr = new XMLHttpRequest();
  xhr.open('GET', url +"buttons/save?Button=" + mode, true);
  xhr.send();
  getButtons();
}




function draw(){
  clear();

  if(curWatering){waterButton.class("active");}
  else{waterButton.class("inactive");}
  if(curStarted){startButton.class("active");}
  else{startButton.class("inactive");}
  // relayState ? Relay_ON : Relay_OFF
  // (IsChecked) ? removeItem($this) : addItem($this);
  //(curWatering ==true)? waterButton.class("active") : waterButton.class("inactive");
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
