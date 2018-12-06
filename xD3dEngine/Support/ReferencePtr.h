#ifndef _REFERENCEPTR_H_
#define _REFERENCEPTR_H_

namespace XD3D
{
	template<typename _Ref>
	class ReferencePtr
	{
	public:
		ReferencePtr() = default;
		ReferencePtr(const ReferencePtr& other){ other.Reference->Ref(); Reference = other.Reference; }
		ReferencePtr(ReferencePtr&& other){ Reference = other.Reference; }
		ReferencePtr(_Ref* p) { p->Ref(); Reference = p; }
		~ReferencePtr() { Reference->UnRef(); }

	public:
		_Ref* operator->() const{
			return this->Reference;
		}

		_Ref& operator*() const{
			return *this->Reference;
		}

		ReferencePtr& operator=(const ReferencePtr& other) const{
			other.Reference->Ref();
			this->Reference = other.Reference;
			return *this;
		}

		ReferencePtr& operator(_Ref* p) const {
			if (p == Reference){
				return *this;
			}
			if (p == nullptr){
				Reference->UnRef();
				Reference = nullptr;
				return *this;
			}
			Reference = p;
			Reference->Ref();
			return *this;
		}

		bool operator==(const ReferencePtr& other) const { return Reference == other.Reference; }
		bool operator==(_Ref* p) const { return Reference == p; }
		bool operator!=(const ReferencePtr& other) const { return Reference != other.Reference; }
		bool operator!=(_Ref* p) const { return Reference != p; }

		bool operator!() const { return Reference != nullptr; }

	public:
		_Ref* Get() const { return Reference; }

		_Ref* Release() const {
			_Ref* Tmp = this->Reference;
			this->Reference = nullptr;
			return Tmp;
		}

		bool Vaild() const { return Reference != nullptr; }

		void Swap(const ReferencePtr& other) {
			_Ref* Tmp = Reference;
			Reference = other.Reference;
			other.Reference = Tmp;
		}

	private:
		_Ref* Reference = nullptr;
	};
}

#endif //!_REFERENCEPTR_H_
