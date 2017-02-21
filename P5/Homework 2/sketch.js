function setup() {
	createCanvas(600, 600);
	background(0);
	data = loadJSON("http://api.open-notify.org/astros.json", gotData, 'jsonp');

}

function gotData(data) {
  console.log(data);
  for (var i=0; i < data.number+1; i++){
  	line(random(600), random(600), random(600), random(600));
  	stroke(random(255), random(255), random(255));
  }
}