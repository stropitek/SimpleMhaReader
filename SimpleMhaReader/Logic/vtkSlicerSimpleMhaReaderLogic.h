/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerSimpleMhaReaderLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerSimpleMhaReaderLogic_h
#define __vtkSlicerSimpleMhaReaderLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes
#include <vtkMRMLScalarVolumeNode.h>

// STD includes
#include <cstdlib>
#include <stdio.h>

// VTK includes
#include <vtkImageData.h>

#include "vtkSlicerSimpleMhaReaderModuleLogicExport.h"

#include "util_macros.h"

using namespace std;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class VTK_SLICER_SIMPLEMHAREADER_MODULE_LOGIC_EXPORT vtkSlicerSimpleMhaReaderLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerSimpleMhaReaderLogic *New();
  vtkTypeMacro(vtkSlicerSimpleMhaReaderLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkSlicerSimpleMhaReaderLogic();
  virtual ~vtkSlicerSimpleMhaReaderLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene* newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);
private:

  vtkSlicerSimpleMhaReaderLogic(const vtkSlicerSimpleMhaReaderLogic&); // Not implemented
  void operator=(const vtkSlicerSimpleMhaReaderLogic&);               // Not implemented
  
  // Attributes
  string mhaPath;
  vector<vector<float> > transforms;
  vector<string> filenames;
  vector<bool> transformsValidity;
  
  vtkSmartPointer<vtkImageData> imgData;
  unsigned char* dataPointer;
  vtkMRMLScalarVolumeNode* imageNode;
  int imageWidth;
  int imageHeight;
  int currentFrame;
  
public:
  // Getters and Setters
  GET(string, mhaPath, MhaPath);
  GET(int, imageWidth, ImageWidth);
  GET(int, imageHeight, ImageHeight);
  GET(int, currentFrame, CurrentFrame);
  void setMhaPath(string path);
  int getNumberOfFrames();
  string getCurrentTransformStatus();
  void updateImage();
  void nextImage();
  void nextValidFrame();
  void previousValidFrame();
  void nextInvalidFrame();
  void previousInvalidFrame();
  void previousImage();
};

#endif
