[![Build Status](https://travis-ci.org/adele-robots/fiona-ros.svg?branch=master)](https://travis-ci.org/adele-robots/fiona-ros)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Integration of FIONA with ROS and ROS-Industrial 
The objective of this project is to integrate FIONA with ROS and ROSIndustrial. This objective is divided into two main tasks: 
1. To adapt the FIONA servers and tools so that they can run ROS-based applications. This will allow developers to build new components for FIONA using the ROS framework, and integrators to include these ROS components in their FIONA applications in a simple and intuitive way.
2. To make the client ROS compliant. This way, ROS and ROS-Industrial applications will be able to connect to and make use of all the functionality from FIONA by just adding this ROS-based FIONA client to their application. 

## What is FIONA?
**Fiona** stands for Framework for Interactive-services Over Natural-conversational Agents and it’s an exciting new online platform to create the next generation of Virtual Agents and Avatars: more interactive, more striking and smarter.

Avatars and Virtual Agents consist of different components and functionalities, for example a TTS, an emotion recognition module, or the appearance of the character. In Fiona these components are called *sparks*.

**Sparks** represent certain features or processes within the operation of the avatar. A Spark is a wrapper for one of those functionalities and it can talk to other sparks about what it is doing. They offer and share information with each other, and they use that information to do a specific thing. For instance, there is a Spark that is able to render the face of a virtual agent in relation to data given to it by other Sparks as the position of the eyes, which in turn is extracted from another Spark that tracks human faces. This is only an example of Sparks working together to share data and make things happen. 

You need **interfaces** for the sparks to be able to communicate with other sparks. Each interface has its own purpose and not all the interfaces can be used with every spark.

There are 2 groups of interfaces: Asking Interfaces and Answering Interfaces. There is always a dialogue between them. The Asking Interfaces call and the Answering Interfaces get the call.

You can find more information in [Fiona´s Wiki.](http://www.sparkingtogether.com/wiki/index.php/User_Guide)

## What is ROS?
ROS (Robot Operating System) provides libraries and tools to help software developers create robot applications. It provides hardware abstraction, device drivers, libraries, visualizers, message-passing, package management, and more. ROS is licensed under an open source, BSD license.

The primary goal of ROS is to support code reuse in robotics research and development. ROS is a distributed framework of processes (aka *Nodes*) that enables executables to be individually designed and loosely coupled at runtime. These processes can be grouped into *Packages* and *Stacks*, which can be easily shared and distributed. ROS also supports a federated system of code *Repositories* that enable collaboration to be distributed as well. This design, from the filesystem level to the community level, enables independent decisions about development and implementation, but all can be brought together with ROS infrastructure tools.

All ROS information and documentation is available at [ROS Wiki.](http://wiki.ros.org/)

## What is ROS-Industrial?
[ROS-Industrial](http://wiki.ros.org/Industrial) is an open-source project that extends the advanced capabilities of ROS software to industrial relevant hardware and applications.

## Communication between FIONA and ROS
So far we know about FIONA, that its functionalities are called Sparks (you could think they are to FIONA what nodes are to ROS) and that sparks need interfaces to communicate.

As we want to establish a bidirectional communication between FIONA and ROS, we are going to focus in two main tasks:

1. ROS getting information from FIONA.
2. FIONA getting information from ROS.

### ROS getting information from FIONA
We establish a request / reply done via a Service. A providing FIONA ROS-based Spark offers a service under a string name, and a ROS node of fiona_pkg client calls the service by sending the request message and awaiting the reply.

#### FIONA ROS-based Sparks
Full code is in [SPARKS](SPARKS) file.

* **ROSAnimationSpark**: Used to make your avatar move.

* **ROSApplicationSpark**: Used to launch a process.

* **ROSAsyncFatalErrorHandlerSpark**: Used to handle errors.

* **ROSAudioSpark**: Used to send and receive audio, and manage audio buffer.

* **ROSCameraSpark**: Used to set position, angles and different parameters of the avatar's camera.

* **ROSConcurrentSpark**: Used to start/stop threads.

* **ROSControlVoiceSpark**: Used to make the avatar start/stop speaking and control its voice.

* **ROSDetectedFacePositionConsumerSpark**: Used to send and receive the position of the detected human face through the camera.

* **ROSEyesSpark**: Used to set the position of the eyes.

* **ROSFaceExpressionSpark**: Used to change the expression of avatar's face.

* **ROSFrameEventSubscriberSpark**: Used to I/O of video frames.

* **ROSNeckSpark**: Used to set avatar's head position.

* **ROSRenderizableSpark**: Used to synchronise video frames.

* **ROSThreadProcSpark**: Used to process multithreads.

* **ROSVoiceSpark**: Used to communicate with a Text To Speech.

* **ROSWindowSpark**: Used to show/hide and get properties of window display.

#### ROS nodes in fiona_pkg
Our fiona_pkg contains a node (client) for each of the FIONA interfaces.  

Services are defined using srv files, so they are compiled into source code by our fiona_pkg client library. As there is a service for each FIONA interface, there is a srv file and a ROS node client for each interface too. This means that each srv file has specific requests and response depending on the interface they want information from.

Some of the interfaces do not need any data coming from the request, so these requests are constant values already established into the launch files of the corresponding fiona_pkg node. From now on, these requests will be called void_request.

Full nodes code is in [fiona_pkg/src](fiona_pkg/src) and srv files are in [fiona_pkg/srv](fiona_pkg/srv).

**Client for ROSAnimationSpark**: Sends the avatar file name as a request and awaits a boolean reply that indicates if the avatar moves or not.
 - Node: fiona_animation_client.cpp.
 - Srv: Animation_srv.srv

**Client for ROSApplicationSpark**: Sends a void_request and awaits a boolean reply that indicates if the process is running or not.
 - Node: fiona_application_client.cpp
 - Srv: Application_srv.srv

**Client for ROSAsyncFatalErrorHandlerSpark**: Sends the exception/error msg and awaits a boolean reply that indicates if that error occurrs.
 - Node: fiona_errorhandler_client.cpp
 - Srv: AsyncFatalErrorHandler_srv.srv

**Clients for ROSAudioSpark: Sends three requests**: "queue" or "dequeue" to select that operation on the audio buffer, the buffer name and the audio size. Then awaits a boolean that indicates if the operation took place.
 - Nodes: fiona_audiobuffer_client.cpp
 - Srv: AudioBuffer_srv.srv

Sends a void_request in order to receive the audio size.
 - Nodes: fiona_audiosize_client.cpp 
  - Srv: AudioSize_srv.srv

**Clients for ROSCameraSpark**: Sends 4 camera parameters and awaits a boolean reply indicating if those parameters were set correctly.
 - Nodes: fiona_cameraparameters_client.cpp
 - Srv: CameraParameters_srv.srv

Sends x, y and z position and awaits a boolean reply indicating if those parameters were set correctly.
 - Nodes: fiona_cameraposition_client.cpp
 - Srv: CameraPosition_srv.srv

Sends x, y and z angles and awaits a boolean reply indicating if those parameters were set correctly.
 - Nodes: fiona_camerarotation_client
 - Srv: CameraRotation_srv.srv

**Client for ROSConcurrentSpark**: Sends a start/stop and awaits a boolean reply that indicates if a thread has been started or stopped.
 - Node: fiona_concurrent_client.cpp
 - Srv: Concurrent_srv.srv

**Client for ROSControlVoiceSpark**: Sends a command for the avatar to start/stop speaking and select the voice. Then the reply is a boolean indicating if the action succeeded.
 - Node: fiona_controlvoice_client.cpp
 - Srv: ControlVoice_srv.srv

**Client for ROSDetectedFacePositionConsumerSpark**: Sends a boolean that indicates if there is a face in front of the camera and its x and y position. The response is a boolean that tells if there is or not a face in that position.
 - Node: fiona_faceposition_client.cpp
 - Srv: DetectedFacePositionConsumer_srv.srv

**Client for ROSEyesSpark**: Sends the position of the eyes in terms of two camera parameters: tilt and pan. The reply verifies if the eyes are indeed where we have indicated.
 - Node: fiona_eyes_client.cpp
 - Srv: Eyes_srv.srv

**Client for ROSFaceExpressionSpark**: Sends the name of the face expression and float indicating its intensity. Then the reply indicates if that is the expression detected.
 - Node: fiona_faceexpression_client.cpp
 - Srv: FaceExpression_srv.srv

**Client for ROSFrameEventSubscriberSpark**: Sends a void_request to receive a boolean that says if a video frame has been detected.
 - Node: fiona_frame_client.cpp
 - Srv: FrameEventSubscriber_srv.srv

**Client for ROSNeckSpark**: Sends the same parameters that fiona_eyes_client but in this cas for the head position. It receives a boolean indicating if a head is in that position.
 - Node: fiona_neck_client.cpp
 - Srv: Neck_srv.srv

**Client for ROSRenderizableSpark**: Sends a void_request to synchronise video frames. Returns a boolean indicating the success.
 - Node: fiona_render_client.cpp
 - Srv: Renderizable_srv.srv

**Client for ROSThreadProcSpark**: Sends a void_request to allow multithread.
 - Node: fiona_threadproc_client.cpp
 - Srv: ThreadProc_srv.srv

**Client for ROSVoiceSpark**: Sends a command of "say"/"stop"/"wait" and a text, to tell the avatar to say that text, to stop speaking or to wait until it ends what it is saying. A boolean reply tells if the action succeded.
 - Node: fiona_voice_client.cpp
 - Srv: Voice_srv.srv

**Clients for ROSWindowSpark**: Sends a command to show, hide or make an operation with a window display and gets a boolean reply.
 - Nodes: fiona_window_client.cpp
 - Srv: Window_srv.srv

Sends a void_request and an integer indicating the colordepth of the window.
 - Nodes: fiona_windowcolordepth_client
 - Srv: WindowColorDepth_srv.srv

In order to see the steps for building fiona_pkg in your catkin workspace, go to [BUILDING.md](BUILDING.md).

### FIONA getting information from ROS
We have a Spark that creates a publisher so we have a topic associated with a particular message type. As we are focusing on ROS-FIONA communication, this Spark will publish a string to this topic, asking ROS the message or the information that FIONA wants to receive.
We could´ve used services as before, but with this, we also show an example of publisher/subscriber nodes.

The publisher in this case is: **ROSTalkerSpark**.

And the subscriber is the node in fiona_pkg: **fiona_listener.cpp**.

## Testing
In order to test our project, we have built one test for each service. In [fiona_pkg/src](fiona_pkg/src) we have the clients and the listener explained before, but we also have servers, which are the ROS-node equivalent of the ROS-Sparks and a talker that is the ROS-node equivalent of ROSTalkerSpark.
Now we can test the services with the tests in [fiona_pkg/tests](fiona_pkg/tests).

To see the steps for testing, go to [TESTING.md](TESTING.md).

## ROS Wiki
All informationabout fiona_pkg is available at http://wiki.ros.org/RaquelSuarez/fiona_pkg too.

## Acknowledgement

<a href="http://rosin-project.eu">
  <img src="http://rosin-project.eu/wp-content/uploads/rosin_ack_logo_wide.png" 
       alt="rosin_logo" height="60" >
</a></br>

Supported by ROSIN - ROS-Industrial Quality-Assured Robot Software Components.  
More information: <a href="http://rosin-project.eu">rosin-project.eu</a>

<img src="http://rosin-project.eu/wp-content/uploads/rosin_eu_flag.jpg" 
     alt="eu_flag" height="45" align="left" >  

This project has received funding from the European Union’s Horizon 2020  
research and innovation programme under grant agreement no. 732287. 
