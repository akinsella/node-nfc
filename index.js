nfc = require(__dirname + '/build/Release/nfc');
events = require('events');

var inherits = function(target, source) {
	for (var k in source.prototype) {
		target.prototype[k] = source.prototype[k];
	}
};

inherits(nfc.Nfc, events.EventEmitter);

module.exports = nfc.Nfc
