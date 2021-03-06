// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License
//
// This example shows how to deserialize a JSON document with ArduinoJson.

#include <ArduinoJson.h>

void setup() {
  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) continue;

  // Memory pool for JSON object tree.
  //
  // Inside the brackets, 200 is the size of the pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use arduinojson.org/assistant to compute the capacity.
  StaticJsonBuffer<200> jsonBuffer;

  // StaticJsonBuffer allocates memory on the stack, it can be
  // replaced by DynamicJsonBuffer which allocates in the heap.
  //
  // DynamicJsonBuffer  jsonBuffer(200);

  // JSON input string.
  //
  // It's better to use a char[] as shown here.
  // If you use a const char* or a String, ArduinoJson will
  // have to make a copy of the input in the JsonBuffer.
  char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  // Root of the object tree.
  //
  // It's a reference to the JsonObject, the actual bytes are inside the
  // JsonBuffer with all the other nodes of the object tree.
  // Memory is freed when jsonBuffer goes out of scope.
  JsonObject& root = jsonBuffer.parseObject(json);

  // Test if parsing succeeds.
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do root["time"].as<long>();
  const char* sensor = root["sensor"];
  long time = root["time"];
  double latitude = root["data"][0];
  double longitude = root["data"][1];

  // Print values.
  Serial.println(sensor);
  Serial.println(time);
  Serial.println(latitude, 6);
  Serial.println(longitude, 6);
}

void loop() {
//  char* intput = "{'message_type' : 1,'requests' : [{ 'type' : 12 , 'value' : 'abc'},{ 'type' : 15, 'value' : 'xyz'}]}";
//  DynamicJsonBuffer jsonBuffer;
//  JsonObject& root = jsonBuffer.parseObject(intput);
//  JsonArray& requests = root["requests"];
//  for (auto& request : requests) {
//     int type = request["type"];
//     const char* value = request["value"];
//     Serial.println(type);
//     Serial.println(value);
//     delay(1000);
//
//  }


//  char json[] = "{'first':'hello','second':'world'}";
//  DynamicJsonBuffer jsonBuffer;
//  JsonObject& root = jsonBuffer.parseObject(json);
//  
//  // using C++11 syntax (preferred):
//  for (auto kv : root) {
//      Serial.println(kv.key);
//      Serial.println(kv.value.as<char*>());
//  }
//  
//  // using C++98 syntax (for older compilers):
//  for (JsonObject::iterator it=root.begin(); it!=root.end(); ++it) {
//      Serial.println(it->key);
//      Serial.println(it->value.as<char*>());
//  }


  //key 항목 가져와서 for면 내용 처리하기
  char json[] = "{'for':[{'infinity':1,'control_type':1},{'contents1':'11','contents2':'22'}]}";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  for (auto kv : root) {
      Serial.println(kv.key);
      Serial.println(kv.value());
  }

}

// See also
// --------
//
// https://arduinojson.org/ contains the documentation for all the functions
// used above. It also includes an FAQ that will help you solve any
// deserialization problem.
//
// The book "Mastering ArduinoJson" contains a tutorial on deserialization.
// It begins with a simple example, like the one above, and then adds more
// features like deserializing directly from a file or an HTTP request.
// Learn more at https://arduinojson.org/book/
// Use the coupon code TWENTY for a 20% discount ❤❤❤❤❤
