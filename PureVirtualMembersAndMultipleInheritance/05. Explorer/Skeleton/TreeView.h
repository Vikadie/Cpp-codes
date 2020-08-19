#pragma once
#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include "Directory.h"
#include "Shortcuts.h"

std::string isFolder(std::shared_ptr<FileSystemObject>& obj, size_t indent) {
	std::shared_ptr<Directory> folder = std::dynamic_pointer_cast<Directory>(obj);
	std::string to_return;

	if (folder) {
		std::sort(folder->items.begin(), folder->items.end(),
			[](const std::shared_ptr<FileSystemObject>& e1, const std::shared_ptr<FileSystemObject>& e2)
			{
				return (e1->getName() < e2->getName());
			});
		size_t size = folder->getSize();
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < indent; j++)
				to_return += "--->";
			to_return += folder->items[i]->getName() + "\n" + isFolder(folder->items[i], indent + 1);
		}
	}
	return to_return;
}

std::string isShortcut(std::shared_ptr<FileSystemObjectsContainer>& shortcut, size_t indent) {

	std::string to_return;

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator itrBegin = shortcut->begin();
	std::vector<std::shared_ptr<FileSystemObject> > itemsVec;
	for (itrBegin; itrBegin != shortcut->end(); itrBegin++)
		itemsVec.push_back(*itrBegin);
	std::sort(itemsVec.begin(), itemsVec.end(), [](const std::shared_ptr<FileSystemObject>& e1, const std::shared_ptr<FileSystemObject>& e2)
		{
			return (e1->getName() < e2->getName());
		});
	std::vector<std::shared_ptr<FileSystemObject> >::iterator itr = itemsVec.begin();
	for (itr; itr != itemsVec.end(); itr++) {
		for (size_t j = 0; j < indent; j++)
			to_return += "--->";
		to_return += (*itr)->getName() + "\n";
		std::shared_ptr<Directory> folder = std::dynamic_pointer_cast<Directory>(*itr);
		if (folder) {
			std::shared_ptr<FileSystemObject> FolderShortcut = std::dynamic_pointer_cast<FileSystemObject>(folder);
			to_return += isFolder(FolderShortcut, indent + 1);
		}
	}

	return to_return;
}

std::string getTreeView(std::vector<std::shared_ptr<FileSystemObject> >& rootObjects) {

	std::string to_return;
	for (auto object : rootObjects) {
		std::shared_ptr<FileSystemObjectsContainer> shortcut = std::dynamic_pointer_cast<FileSystemObjectsContainer>(object);
		if (shortcut)
			to_return += object->getName() + "\n" + isShortcut(shortcut, 1);
		else
			to_return += object->getName() + "\n" + isFolder(object, 1);
	}
	return to_return;
}

#endif // !TREE_VIEW_H
