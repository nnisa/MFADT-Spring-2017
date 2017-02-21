var data;

function setup() {
	createCanvas(400, 400)
	data = loadJSON("data.json");
}

// var bytes = '{"name": "your name", "counter":0}'
// var data = JSON.parse(bytes)


function draw() {
	background(128, 80, 200)
	console.log(data.name)
	console.log(data.counter)
	data.counter +=1
  
}