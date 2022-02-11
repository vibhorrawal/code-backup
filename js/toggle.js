function toggle() { // can also be done like toggle(...args)
    let pointer = 0, n = arguments.length;
    let args = arguments;
    return function() {
        console.log(args[pointer++ % n]);
    }
}

var hello = toggle("hello");
hello();
hello();

var onOff = toggle("on", "off");
onOff();
onOff();
onOff();

var speed = toggle("slow", "medium", "fast");
speed();
speed();
speed();

var nill = toggle();
nill();
nill();