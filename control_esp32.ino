#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "G";
const char* password = "1234567890";

WebServer server(80);

// หน้าเว็บ HTML
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>ESP32 Serial Control</title>
<style>
body{
    font-family: Arial;
    text-align: center;
    margin-top: 80px;
    background-color: #f2f2f2;
}
button{
    width:180px;
    height:60px;
    font-size:22px;
    margin:15px;
    border:none;
    border-radius:10px;
    color:white;
    cursor:pointer;
}
.on{
    background-color:green;
}
.off{
    background-color:red;
}
</style>
</head>

<body>

<h1>ESP32 Web Control</h1>

<button class="on" onclick="location.href='/ON'">ON</button>
<button class="off" onclick="location.href='/OFF'">OFF</button>

</body>
</html>
)rawliteral";

// แสดงหน้าเว็บ
void handleRoot() {
  server.send(200, "text/html", webpage);
}

// กดปุ่ม ON
void handleOn() {
  Serial.println("Button ON Pressed");
  server.send(200, "text/html", webpage);
}

// กดปุ่ม OFF
void handleOff() {
  Serial.println("Button OFF Pressed");
  server.send(200, "text/html", webpage);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("Connecting WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/ON", handleOn);
  server.on("/OFF", handleOff);

  server.begin();

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}