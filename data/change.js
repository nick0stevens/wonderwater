
  var keyword = "balcony garden";
  var screenInit = 0;
	var newVari = 0;
	var oldVari = 10;
  var textS;
 var curPeriod = 0;
 var curInterval = 0;
 var curSInterval = 0;
 var curThreshold = 0;
 var curWatering = 0;
 var last = 0;

//var url = 'http://192.168.20.10'
var url = '';
//var url = 'http://wonderWater.local/';



function setup() {


  createCanvas(640, 480);

  heading = createP("Change any of the variables here");
  heading.position(20, 5);
  heading.class("h1");

///////// period
  periodText = createP("watering period");
  periodText.position(20, 45);
  periodText.class("tooltip"); // assign a class to be used by the CSS sheet
  periodTip = createSpan("period of each watering");
  periodTip.class("tooltiptext");
  periodTip.parent(periodText);
  periodInput = createInput("enter Period");
  periodInput.id("periodValue");
  periodInput.position(20, 85);
  periodButton = createButton('submit');
  periodButton.id("period");
  periodButton.position(170, 85);
  document.getElementById('period').onclick = function(e)
  {
    inputVariable("period","periodValue");
  };

///////// interval

  intervalText = createP("interval");
  intervalText.position(20, 125);
  intervalText.class("tooltip"); // assign a class to be used by the CSS sheet
  intervalTip = createSpan("period between waterings");
  intervalTip.class("tooltiptext");
  intervalTip.parent(intervalText);
  intervalInput = createInput("enter interval");
  intervalInput.id("intervalValue");
  intervalInput.position(20, 165);
  intervalButton = createButton('submit');
  intervalButton.id("interval");
  intervalButton.position(170, 165);
  document.getElementById('interval').onclick = function(e)
  {
    inputVariable("interval","intervalValue");
  };


/////////  sensor Interval

  sIntervalText = createP("sensor interval");
  sIntervalText.position(20, 205);
  sIntervalText.class("tooltip"); // assign a class to be used by the CSS sheet
  sIntervalTip = createSpan("period between checking moisture");
  sIntervalTip.class("tooltiptext");
  sIntervalTip.parent(sIntervalText);
  sIntervalInput = createInput("eneter sensor interval");
  sIntervalInput.id("sIntervalValue");
  sIntervalInput.position(20, 245);
  sIntervalButton = createButton('submit');
  sIntervalButton.id("sInterval");
  sIntervalButton.position(170, 245);
  document.getElementById('sInterval').onclick = function(e)
  {
    inputVariable("sInterval","sIntervalValue");
  };

/////////  moisture threshold

  thresholdText = createP("moisture threshold");
  thresholdText.position(20, 285);
  thresholdText.class("tooltip"); // assign a class to be used by the CSS sheet
  thresholdTip = createSpan("threshold below which watering commences");
  thresholdTip.class("tooltiptext");
  thresholdTip.parent(thresholdText);
  thresholdInput = createInput("enter sensor interval");
  thresholdInput.id("thresholdValue");
  thresholdInput.position(20, 325);
  thresholdButton = createButton('submit');
  thresholdButton.id("threshold");
  thresholdButton.position(170, 325);
  document.getElementById('threshold').onclick = function(e)
  {
    inputVariable("threshold","thresholdValue");
  };

  editButton = createButton('edit webpage');
  editButton.id('edit');
  editButton.position(350, 165);
  document.getElementById('edit').onclick = function(e)
  {
    linkPage("edit.htm");
  };

  flashButton = createButton('flash firmware');
  flashButton.position(450, 165);
  flashButton.id('flash');
  document.getElementById('flash').onclick = function(e)
  {
   linkPage("flash.html");
  };


  flashButton = createButton('start page');
  flashButton.position(550, 165);
  flashButton.id('start');
  document.getElementById('start').onclick = function(e)
  {
    linkPage("index.html");
  };

  textAlign(LEFT);
  textSize(50);
  getVariables();

}



function inputVariable(_variable,_valueId){
  console.log(_variable);
  console.log(_valueId);
  var _value = document.getElementById(_valueId).value;
  console.log(_value);
  var xhr = new XMLHttpRequest();
  var request = url + "variables/save?" + _variable + "=" + _value;
  xhr.open('GET', request, true);
  console.log(request);
  xhr.send();
  getVariables();
}

function getVariables(){
   console.log("get variables");
   var address = url + "/variables";
   console.log(address);
   loadJSON(address, loadVariables);
}

function linkPage(page){
   console.log("got to edit page");
   var address = url + page;
   window.location.href = address;
}

function loadVariables(newVariables){
  //Get the loaded JSON data
  console.log("commencing loading");
  console.log(newVariables);
  //oldVari= newVariables.variTest;
  //{"period":21"interval":44"sInterval":0"threshold":89"irrigating":0}
  curPeriod = newVariables.period; // get the main.humidity out of the loaded JSON
  curInterval = newVariables.interval;
  curSInterval = newVariables.sInterval;
  curThreshold = newVariables.threshold;
  curWatering = newVariables.irrigating;
  console.log(curPeriod); // inspect the humidity in the console
  console.log(curInterval); // inspect the humidity in the console
  console.log(oldVari); // inspect the humidity in the console
  console.log("loaded");
  //text("old Variable", 180, 140);
  //text(oldVari, 80, 140);
  //redraw();
}

function draw(){
  clear();
  textSize(20);
	text(curPeriod, 95, 75);
  text(curInterval, 95, 155);
  text(curSInterval, 95, 235);
  text(curThreshold, 95, 315);
/*
if(millis()>last +2000){
getVariables();
last = millis();
}
*/



	//if(screenInit == 0){

  //screenInit = 1;
//}
//noLoop();
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
