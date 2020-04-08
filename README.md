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
