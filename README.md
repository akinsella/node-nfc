node-nfc
========

Generate Xcode project:

	node-gyp configure -- -f xcode

Build bindings and test project:

	node-gyp configure build && mocha test