function setup() {
	createCanvas(400, 400)
}

var bytes = '{"temp": 70}'
var data = JSON.parse(bytes)

function draw() {
	background(128, 80, 200)
	console.log(data.temp)
}