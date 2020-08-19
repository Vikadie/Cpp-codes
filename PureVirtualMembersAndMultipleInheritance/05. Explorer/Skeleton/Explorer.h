#pragma once
#ifndef EXPLORER_H
#define EXPLORER_H

#include "Directory.h"
#include "File.h"

class Explorer {
	std::shared_ptr<Shortcuts> shortcuts; //sortcuts container
	std::vector<std::shared_ptr<FileSystemObject> > cutObject; //cut object container
	std::vector<std::shared_ptr<FileSystemObject> >& rootObjects; // root Folder container
	std::shared_ptr<Directory> currentFolder;
public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject> >& rootObjectsAddress): rootObjects(rootObjectsAddress), currentFolder(nullptr), shortcuts(nullptr) {}

	void createFile(std::string filename, std::string content) {
		std::shared_ptr<FileSystemObject> newObject = std::make_shared<File>(filename, content);
		if (!currentFolder) 
			rootObjects.push_back(newObject);
		else
			currentFolder->add(newObject);
	}

	void createDirectory(std::string dirName) {
		std::shared_ptr<FileSystemObject> newObject = std::make_shared<Directory>(dirName);
		if (!currentFolder)
			rootObjects.push_back(newObject);
		else
			currentFolder->add(newObject);
	}

	void cut(std::string name) {
		// not used anymore std::shared_ptr<FileSystemObject> newObjectToCut = std::make_shared<FileSystemObject>(name);
		// check if it is in root
		if (!currentFolder) {
			for (size_t i = 0; i < rootObjects.size(); i++)
				if (rootObjects[i]->getName() == name) {
					cutObject.push_back(rootObjects[i]); 
					rootObjects.erase(rootObjects.begin() + i);
					break;
				}
		}
		else
			for (size_t i = 0; i < currentFolder->getSize(); i++)
				if (currentFolder->items[i]->getName() == name) {
					cutObject.push_back(currentFolder->items[i]);
					currentFolder->remove(currentFolder->items[i]);
					break;
				}
	}

	void paste() {
		auto cutElement = cutObject.back();
		cutObject.pop_back();
		if (!currentFolder)
			rootObjects.push_back(cutElement);
		else {
			currentFolder->add(cutElement);
			cutElement->setParent(currentFolder);
		}
	}

	void createShortcut(std::string name) {
		if (!shortcuts) {
			shortcuts = std::make_shared<Shortcuts>();
			std::shared_ptr<FileSystemObject> newObject = shortcuts;
			rootObjects.push_back(shortcuts);
		}
		if (!currentFolder) {
			for (size_t i = 0; i < rootObjects.size(); i++)
				if (rootObjects[i]->getName() == name) {
					shortcuts->add(rootObjects[i]); break;
				}
		} else
			for (size_t i = 0; i < currentFolder->getSize(); i++)
				if (currentFolder->items[i]->getName() == name) {
					shortcuts->add(currentFolder->items[i]); break;
				}
	}

	void navigate(std::string path) {
		if (path == "..") {
			// return one level up
			std::shared_ptr<Directory> temp = nullptr;
			std::shared_ptr<Directory> parent = nullptr;
			if (currentFolder->getParent().lock())
				temp = std::dynamic_pointer_cast<Directory>(currentFolder->getParent().lock());
			if (!temp)
				currentFolder = nullptr;
			else {
				currentFolder = temp;
				/*parent = std::dynamic_pointer_cast<Directory>(temp);
				if (parent)
					currentFolder->setParent(parent);*/
			}
		}
		else {
			// find the folder and go down
			if (!currentFolder) {
				for (size_t i = 0; i < rootObjects.size(); i++)
					if (rootObjects[i]->getName() == path) {
						std::shared_ptr<Directory> temp = std::dynamic_pointer_cast<Directory>(rootObjects[i]);
						//currentFolder->setParent();
						currentFolder = temp; break;
					}
			} else 
			for (size_t i = 0; i < currentFolder->getSize(); i++)
				if (currentFolder->items[i]->getName() == path) {
					std::shared_ptr<Directory> temp = std::dynamic_pointer_cast<Directory>(currentFolder->items[i]);
					std::shared_ptr<Directory> parent = currentFolder;
					currentFolder = temp;
					currentFolder->setParent(parent);
					break;
				}
		}
	}
};

#endif // !EXPLORER_H