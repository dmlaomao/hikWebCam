# hikWebCam

## Environment
VS2015(v140), opencv331, hikvision SDK_V5.3.1.22(for Windows x64)

## Works
* Packaged hik sdk to `HikWebCam` class.
* Added multi camera input stream supprt.
* VS2015 demo.

## Usage
* Clone this repo to <your_path>.
* Open `<your_path>/webCamTest/webCamTest.sln` project.
* Config your opencv path. 
* Add `<your_path>/3rdparty/bin/` to your environment variable path.
* Init an object with `HikWebCam webCam("your_ip", "your_usrname", "your_pwd", "your_portnum");`
* Run the demo.
