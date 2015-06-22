var express = require('express');
var app = express();
var expressWs = require('express-ws')(app);

var five = require("johnny-five"),
    board = new five.Board({repl:false});

var horizontal, vertical, relay;

app.use(express.static('public'));

app.ws('/ws', function(ws) {
  ws.on('message', function incoming(message) {
    if (horizontal) horizontal.to(message.readFloatLE(0));
    if (vertical) vertical.to(message.readFloatLE(4));
    if (relay) {
      if (message.readFloatLE(8) > 0)
        relay.low();
      else
        relay.high();
    }
  });
});

app.listen(8080);

board.on("ready", function() {
  horizontal = new five.Servo({pin:10, type:'continuous'});
  vertical = new five.Servo({pin:9, type:'continuous'});
  relay = new five.Pin({pin:7, mode:1, type:'digital'});
  relay.high();
});

