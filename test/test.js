var mocha = require('mocha');
var should = require('should');
var Nfc = require('..');
var util = require('util');

describe('nfc', function(){

	describe('Ping', function(){
		it('Should ping', function(){
			var nfc = new Nfc();
			nfc.on('ping', function(data) {
				console.log('Ping data: ' + util.inspect(data));
				data.should.equal('Hello World!');
			});

			nfc.ping('Hello World!');
		});
	});

});