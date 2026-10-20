import http.server
import os

os.chdir("server")

http.server.HTTPServer(("",8000),http.server.SimpleHTTPRequestHandler).serve_forever()
