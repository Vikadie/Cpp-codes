#pragma once
#ifndef LECTURE_H
#define LECTURE_H

#include "Resource.h"
#include "ResourceType.h"
#include <algorithm>

namespace SoftUni {

	using SoftUni::ResourceType;
	using SoftUni::Resource;

	class Lecture {
	private:
		std::vector<Resource> lectures;

	public:
		std::map<ResourceType, int> numberOfResourcesByType;
		bool filledMap = false;
		Lecture() {}
		Lecture(std::vector<Resource> lectureSet):
			lectures(lectureSet) {}

		Lecture operator<< (const Resource& r) {
			std::vector<Resource>::iterator it = this->lectures.begin();
			for (it; it != this->lectures.end();) {
				if ((*it).getId() == r.getId())
					it = this->lectures.erase(it);
				else
					it++;
			}
			this->lectures.push_back(r);
			std::sort(this->lectures.begin(), this->lectures.end());
			return Lecture{ this->lectures };
		}


		std::vector<Resource>::const_iterator begin() const {
			return lectures.begin();
		}

		std::vector<Resource>::const_iterator end() const {
			return lectures.end();
		}

		const int operator[] (ResourceType type) {
			if (!filledMap) {
				for (const auto r : lectures) {
					numberOfResourcesByType[r.getType()]++;
				}
				filledMap = true;
			}
			for (auto pair : numberOfResourcesByType)
				if (pair.first == type) {
					return pair.second;
				}
			return -1;
		}
	};

	std::vector<ResourceType>& operator<< (std::vector<ResourceType>& resources, const Lecture& lecture) {
		std::set<ResourceType> resourceSet; 
		for (const auto r : lecture) {
			resourceSet.insert(r.getType());
		}
		for (const auto t : resourceSet)
			resources.emplace_back(t);
		return resources;
	}

};

#endif LECTURE_H