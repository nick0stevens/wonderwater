
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
  heading.position(20, 0);
  heading.class("h1");

///////// period
  periodText = createP("current watering period");
  periodText.position(20, 40);
  periodText.class("tooltip"); // assign a class to be used by the CSS sheet
  periodTip = createSpan("period of each watering");
  periodTip.class("tooltiptext");
  periodTip.parent(periodText);
  periodInput = createInput("enter new period here");
  periodInput.id("periodValue");
  periodInput.position(20, 95);
  periodButton = createButton('submit');
  periodButton.id("period");
  periodButton.position(170, 95);
  document.getElementById('period').onclick = function(e)
  {
    inputVariable("period","periodValue");
  };

///////// interval

  intervalText = createP("current interval");
  intervalText.position(20, 120);
  intervalText.class("tooltip"); // assign a class to be used by the CSS sheet
  intervalTip = createSpan("period between waterings");
  intervalTip.class("tooltiptext");
  intervalTip.parent(intervalText);
  intervalInput = createInput("enter new interval here");
  intervalInput.id("intervalValue");
  intervalInput.position(20, 175);
  intervalButton = createButton('submit');
  intervalButton.id("interval");
  intervalButton.position(170, 175);
  document.getElementById('interval').onclick = function(e)
  {
    inputVariable("interval","intervalValue");
  };


/////////  sensor Interval

  sIntervalText = createP("current sensor interval");
  sIntervalText.position(20, 200);
  sIntervalText.class("tooltip"); // assign a class to be used by the CSS sheet
  sIntervalTip = createSpan("period between checking moisture");
  sIntervalTip.class("tooltiptext");
  sIntervalTip.parent(sIntervalText);
  sIntervalInput = createInput("enter new sensor interval here");
  sIntervalInput.id("sIntervalValue");
  sIntervalInput.position(20, 255);
  sIntervalButton = createButton('submit');
  sIntervalButton.id("sInterval");
  sIntervalButton.position(170, 255);
  document.getElementById('sInterval').onclick = function(e)
  {
    inputVariable("sInterval","sIntervalValue");
  };

/////////  moisture threshold

  thresholdText = createP("current moisture threshold");
  thresholdText.position(20, 280);
  thresholdText.class("tooltip"); // assign a class to be used by the CSS sheet
  thresholdTip = createSpan("threshold below which watering commences");
  thresholdTip.class("tooltiptext");
  thresholdTip.parent(thresholdText);
  thresholdInput = createInput("enter  new threshold here");
  thresholdInput.id("thresholdValue");
  thresholdInput.position(20, 335);
  thresholdButton = createButton('submit');
  thresholdButton.id("threshold");
  thresholdButton.position(170, 335);
  document.getElementById('threshold').onclick = function(e)
  {
    inputVariable("threshold","thresholdValue");
  };

  editButton = createButton('edit webpage');
  editButton.id('edit');
  editButton.position(20, 400);
  document.getElementById('edit').onclick = function(e)
  {
    window.location.href = "edit.html";
  };

  flashButton = createButton('flash firmware');
  flashButton.position(120, 400);
  flashButton.id('flash');
  document.getElementById('flash').onclick = function(e)
  {
   window.location.href = "flash.html";
  };


  flashButton = createButton('BACK');
  flashButton.position(220, 400);
  flashButton.id('start');
  document.getElementById('start').onclick = function(e)
  {
    window.location.href = "index.html";
  };

  textAlign(LEFT);
  textSize(20);

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
  // var address = url + "/variables";
   loadJSON("/variables", loadVariables);
}


function loadVariables(newVariables){
  //Get the loaded JSON data
  curPeriod = newVariables.period;
  curInterval = newVariables.interval;
  curSInterval = newVariables.sInterval;
  curThreshold = newVariables.threshold;
  curWatering = newVariables.irrigating;
  console.log("loaded variables");

}

function draw(){

  clear();
  textSize(15);
	text(curPeriod, 20, 87);  text("secs", 40, 87);
  text(curInterval, 20, 167); text("mins", 40, 167);
  text(curSInterval, 20, 247); text("mins", 40, 247);
  text(curThreshold, 20, 327); text("/100", 40, 327);

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
