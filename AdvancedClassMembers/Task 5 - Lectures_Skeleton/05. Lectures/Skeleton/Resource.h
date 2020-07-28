#pragma once

#include "ResourceType.h"

namespace SoftUni {
	using SoftUni::ResourceType;

	class Resource {
	private:
		int id = 0;
		std::string link = "";
		std::string type = "";
		ResourceType typeRessourceType;
	public:
		Resource() {}
		Resource(int id, std::string t, std::string str) :
			id(id),
			type(t),
			link(str) {
			ResourceType typeResourceType = convert(type);
		}

		bool operator<(const Resource& r) const
		{
			return id < r.id;  //assume that you compare the record based on id
		}

		ResourceType convert(std::string str) const {
			for (auto& c : str) c = toupper(c);
			if (str == "PRESENTATION")
				return PRESENTATION;
			else if (str == "DEMO")
				return DEMO;
			else if (str == "VIDEO")
				return VIDEO;
		}

		ResourceType getType() const {
			return convert(type);
		}

		int getId() const {
			return this->id;
		}

		std::string getLink() const {
			return this->link;
		}

		friend std::istream& operator>> (std::istream& in, Resource& r);
	};

	std::istream& operator>> (std::istream& in, Resource& r) {
		return in >> r.id >> r.type >> r.link;
	}

	std::ostream& operator<< (std::ostream& out, const Resource& r) {
		return out << r.getId() << " " << r.getType() << " " << r.getLink();
	}
};