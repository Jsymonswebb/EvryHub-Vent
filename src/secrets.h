#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "Evryhub-Vent"
 
const char WIFI_SSID[] = "HOME";
const char WIFI_PASSWORD[] = "AkJ197219992001";
const char AWS_IOT_ENDPOINT[] = "ah1nte2vfjrs0-ats.iot.ca-central-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWDCCAkCgAwIBAgITdcdHFLwwOcnzBE1yuQGIcL1A9DANBgkqhkiG9w0BAQsF
ADBNMUswSQYDVQQLDEJBbWF6b24gV2ViIFNlcnZpY2VzIE89QW1hem9uLmNvbSBJ
bmMuIEw9U2VhdHRsZSBTVD1XYXNoaW5ndG9uIEM9VVMwHhcNMjIxMDA1MTg0MTQ4
WhcNNDkxMjMxMjM1OTU5WjAeMRwwGgYDVQQDDBNBV1MgSW9UIENlcnRpZmljYXRl
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA+8E8MYluO7xsoz84y9oA
PsNLyG9eyObJRtIio3bCAoMeOgF+x4uRoYfkN+eJ9774ZuETEJceppG5/0MG2FFl
4sh+8hcAJ9ADXPkC6RbIDvqsQk+ylvYteXhvkK9ECdH7S38g0L24OX29MokNAOtT
z3r7FCqQjeOfsYanZ4gs5YvJAaEfnix08rMDbWUuQAHsAUoOa5hxAzbjrJbvbquB
14yKnZQsHmv6Qmmo725WLOzzbN0s92TTU/gKjoTBH4pyU8VBzZn/yMUvC6j7qGWX
veI8NJRoajsZPsNpHukA+WQPsmP/K1JglxjoIuEKhyI/pahrDyMMUQElZW2s22+X
awIDAQABo2AwXjAfBgNVHSMEGDAWgBTu2alzXfXvinl1KgaIvPAz7Z/8GzAdBgNV
HQ4EFgQUO0tLcZTmKNsy2jZf/TwLEJRP77AwDAYDVR0TAQH/BAIwADAOBgNVHQ8B
Af8EBAMCB4AwDQYJKoZIhvcNAQELBQADggEBAHE3box83prUepgQ0HR3zsR2Eqmi
pPDbgayuok+QRrasT2sDnzpqYitOZmJWB+WtO7izMn1UQ3Qi0AD1RnB0aRaKits7
0kjfWEWGL0q2JzLxKzir8G5wEOBvypytky6pe77srPF0eFB2K4pNlcbG34coPnKn
E0lDaXh/OjGiNSWEXDpuw7c6qFZbZ9anv6wdHJWEBbtbbtHwT2Z3llEDWfSo4C+5
T22HDyNZMl0H27+eSZ9ScXvYGqsMLvyeNxLu/1O1RpbY4pQZQxCYREPTZYrD7I+J
MBPnWK9Zrha994E6fto+03Xo5MZZWT4eAD6GiOOdLdIa4VIQkl7RzYrg21k=
-----END CERTIFICATE-----
)KEY";
 
// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA+8E8MYluO7xsoz84y9oAPsNLyG9eyObJRtIio3bCAoMeOgF+
x4uRoYfkN+eJ9774ZuETEJceppG5/0MG2FFl4sh+8hcAJ9ADXPkC6RbIDvqsQk+y
lvYteXhvkK9ECdH7S38g0L24OX29MokNAOtTz3r7FCqQjeOfsYanZ4gs5YvJAaEf
nix08rMDbWUuQAHsAUoOa5hxAzbjrJbvbquB14yKnZQsHmv6Qmmo725WLOzzbN0s
92TTU/gKjoTBH4pyU8VBzZn/yMUvC6j7qGWXveI8NJRoajsZPsNpHukA+WQPsmP/
K1JglxjoIuEKhyI/pahrDyMMUQElZW2s22+XawIDAQABAoIBACh/Bt25C6BUSO1h
iBNSd+OgqpoNQCP067+WobfFrKOWz8/o2anji4N+RnmvpwPRFkgGQHjUtjt5CYBE
Gd/GCCuYsMLkbEP7M+9KpusznO675+WqyEF8TAhUFS4i40DpJBEa2/535iBpV3u/
i/Xv5MVlNOojhqksSk3WKSuAPiiWKAyYGDUteMTuqqSuyYaY3febW8/qzRyWt6f6
P9tyDq4G7EwuaHHhzKR8dPfd13MOjDaBKD57YU4iljlUUH+pslmr4yXfBYdVNAwe
5b4sB4R6RVrGl0xdkAYC+Uildk2Y2lPaFB4TmYhdeozTXcmybSC3JUp+ATn0x5lH
WkcDRnECgYEA/uhsZGCk9MAyiDkN+vd/x7WGCo+GUerm1X1Cs8PTR2YwNWELoyRC
6QN/XWiMY1R5B5RhL+kniyyZ5AoHQSz5ytOJArDCzxmcM47qNM+r0nYUT8KNtBSf
gi52oGnzgBEN5/Y6RTdhuJU7xKz/oo97wBdyb8u6tc1cc4R8v4jyzRcCgYEA/NVa
f1/G+t6KybSfH7m1wWaXZUFeM7PUly1jfMFh0T5G9I9fYhFFzoHEIlVrzNgECgd2
61ZSqCKcW1x1Gg2cy79qgveuppkLRibzq5L88nwRfDqQMpZHabY7ODo14ZR7EYXB
47egPN4wzF8ORIknYHHKyuYT4rrdVePhcdq7BM0CgYAVcmS8RU1bslgOEg7VEMHV
gbZXaR/6AHOPfsx/53f9R+HCe/nIriJbDIpIx6UYLmFIe/l5WHqVQRlpkFZv62LQ
599dNJYPaq4zwFCARQDF4l1vIIVfo2SQRWyBrqhoHAc5fwQEEtbL+vJeZ9fSS5Qz
40UjltaMuUyQA5OjYdhb3QKBgQD02P1R+wPssRWA7u1mwOcWi260PVCoC1Ams2r0
Ryaeh4wZjLsXcpjCuwKhKU5DSzLmL4Jnt+pGL3ZyN6CkAWjGG/JfMNOvPOkhH9m8
X5WckrAwOVqp0sUHx9WjxyOk+LESMBGroImKSLbDRI7Bqn06thho09WQLdzpL82F
AAk7RQKBgG+939oVWOBfavrFqYPOfBIs85hk2qpt+gBd2wEH7ZTmj1ays5hJbRhW
aQgSemviH9SBjIXdalku5L4yxbwCd+6YBffrNITYQCPxlCGNKPhH4vHxGOGoW05u
oUl/RypOjZH1tJkSYONgTmopKytmCyYZ7La5HjiX8B2kOtKx0kDt
-----END RSA PRIVATE KEY-----
)KEY";