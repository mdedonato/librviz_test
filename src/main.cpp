/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// BEGIN_TUTORIAL

// The main() for this "myviz" example is very simple, it just
// initializes ROS, creates a QApplication, creates the top-level
// widget (of type "MyViz"), shows it, and runs the Qt event loop.

#include <QApplication>
#include <ros/ros.h>
#include "myviz.h"


	myAPP::myAPP(int &argc, char *argv[]) :
			QApplication(argc,argv)
	{

	}
bool myAPP::notify(QObject *receiver_, QEvent *event_)
{
  try
  {
    return QApplication::notify(receiver_, event_);
  }
  catch (std::exception &ex)
  {
    std::cerr << "std::exception was caught" << std::endl;
    std::cerr << ex.what() << std::endl;

  }

  return false;
}


myAPP::~myAPP()
{
}
int main(int argc, char **argv)
{
  if( !ros::isInitialized() )
  {
    ros::init( argc, argv, "myviz", ros::init_options::AnonymousName );
  }

  myAPP app( argc, argv );

  MyViz* myviz = new MyViz();
  myviz->show();

  app.exec();

  delete myviz;
}


