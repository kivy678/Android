# -*- coding:utf-8 -*-

##################################################################################################

from tornado.wsgi import WSGIContainer
from tornado.httpserver import HTTPServer
from tornado.web import Application, FallbackHandler

from tornado.ioloop import IOLoop

from web.runner import app
from web.websocket import MYWebSocket

##################################################################################################

"""
def getServer(port):
    server = HTTPServer(WSGIContainer(app))
    server.listen(port)
    return IOLoop.instance()
"""

def getServer2(port):
    container = WSGIContainer(app)
    server = Application([
        (r'/websocket/', MYWebSocket),
        (r'.*', FallbackHandler, dict(fallback=container))
    ])
    server.listen(port)
    return IOLoop.instance().start()

if __name__ == '__main__':
    # Flask running
    app.run(host="0.0.0.0", port=7777, debug=True)

    # tornadorunning
    #server = getServer2(7777)
    #server.start()

    print("Web done...")