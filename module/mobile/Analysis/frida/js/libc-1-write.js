
// ssize_t write(int fd, const void *buf, size_t count);
Interceptor.attach(Module.getExportByName(null, 'write'), {
  onEnter: function (args) {
    //console.log('Context  : '   + JSON.stringify(this.context));
    //console.log('ReturnAddr : ' + this.returnAddress);

    this.fd     = args[0].toInt32();
    this.buf    = args[1];
    this.count  = args[2].toInt32();
  },
  onLeave: function (result) {
    var numBytes = result.toInt32();

    if (numBytes > 0) {
      send(hexdump(this.buf, { length: numBytes, ansi: true }));
    }

    send('WriteCount   : ' + numBytes);
  }
})
