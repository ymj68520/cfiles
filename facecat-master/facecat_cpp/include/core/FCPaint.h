/*����èFaceCat��� v1.0
 1.��ʼ��-�󶴳���Ա-�Ϻ����׿Ƽ���ʼ��-����KOL-�յ� (΢�ź�:suade1984);
 2.���ϴ�ʼ��-�Ϻ����׿Ƽ���ʼ��-Ԭ����(΢�ź�:wx627378127);
 3.���ϴ�ʼ��-Ф����(΢�ź�:xiaotianlong_luu);
 4.���Ͽ�����-������(΢�ź�:chenxiaoyangzxy)������-���(΢�ź�:cnnic_zhu)
 5.�ÿ�ܿ�ԴЭ��ΪBSD����ӭ�����ǵĴ�ҵ����и���֧�֣���ӭ���࿪���߼��롣
 ����C/C++,Java,C#,iOS,MacOS,Linux�����汾��ͼ�κ�ͨѶ�����ܡ�
 */

#ifndef __FCPAINT_H__
#define __FCPAINT_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace FaceCat{
	template <class numtype>
	/*
	* �Զ��弯��
	*/
	class ArrayList{
	public:
		/*
		* ����
		*/
		numtype *m_ary;
		/*
		* ��С
		*/
		int m_size;
		/*
		* ����
		*/
		int m_capacity;
		/*
		* ģʽ
		*/
		int m_mode;
		/*
		* ��������
		*/
		int m_step;
	public:
		/*
		* ���캯��
		*/
		ArrayList(){
			m_size = 0;
			m_ary = 0;
			m_capacity = 4;
			m_step = 4;
			m_mode = 0;
		}
		/*
		* ���캯��
		* @param capacity ����
		*/
		ArrayList(int capacity){
			m_size = 0;
            m_ary = 0;
            m_capacity = capacity;
            m_step = 4;
			m_mode = 0;
		}
		/*
		* ���
		* @param value ����
		*/
		void add(numtype value){
			m_size += 1;
			if(!m_ary){
				if(m_mode == 0){
					m_ary = new numtype[m_capacity];
				}
				else{
					m_ary = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE); 
				}
			}
			else{
				if(m_size > m_capacity){
					if(m_mode == 0){
						m_capacity = (int)(m_size * 1.5);
						numtype *newAry = new numtype[m_capacity];
						for(int i = 0;i < m_size - 1; i++){
							newAry[i] = m_ary[i];
						}
						delete[] m_ary;
						m_ary = newAry;
					}
					else{
						m_capacity += m_step;
						numtype *newAry = (numtype*)VirtualAlloc(m_ary, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
						if(newAry){
							m_ary = newAry;
						}
						else{
							newAry = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
							MoveMemory(newAry, m_ary, sizeof(numtype) * (m_size - 1));
							VirtualFree(m_ary, 0, MEM_RELEASE);
							m_ary = newAry;
						}
					}
				}
			}
			m_ary[m_size - 1] = value;
		}

		/*
		* �������
		* @param ary ����
		* @param size ��С
		*/
		void addranges(numtype *ary, int size){
            m_ary = ary;
			m_size = size;
            m_capacity = m_size;
            m_step = 4;
		}
		/*
		* ��ȡ����
		*/
		int capacity(){
			return m_capacity;
		}
		/*
		* ���
		*/
		void clear(){
			if(m_ary){
				if(m_mode == 0){
					delete[] m_ary;
				}
				else{
					VirtualFree(m_ary, 0, MEM_RELEASE);
				}
				m_ary = 0;
			}
			m_size = 0;
		}
		/*
		* ��ȡ����
		*/
		numtype get(int index){
			return m_ary[index];
		}
		/*
		* ��������
		* @param index ����
		* @param value ����
		*/
		void insert(int index,numtype value){
			m_size += 1;
			if(!m_ary){
				if(m_mode == 0){
					m_ary = new numtype[m_capacity];
				}
				else{
					m_ary = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE); 
				}
			}
			else{
				bool build = false;
				if(m_size > m_capacity){
					if(m_mode == 0){
						m_capacity = (int)(m_size * 1.5);
						numtype *newAry = new numtype[m_capacity];
						for(int i = 0;i < m_size - 1;i++){
							if(i < index){
								newAry[i] = m_ary[i];
							}
							else if( i >= index){
								newAry[i + 1] = m_ary[i];
							}
						}
						delete[] m_ary;
						m_ary = newAry;
						build = true;
					}
					else{
						m_capacity += m_step;
						numtype *newAry = (numtype*)VirtualAlloc(m_ary, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
						if(newAry){
							m_ary = newAry;
						}
						else{
							newAry = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
							MoveMemory(newAry, m_ary, sizeof(numtype) * (m_size - 1));
							VirtualFree(m_ary, 0, MEM_RELEASE);
							m_ary = newAry;
						}
					}
				}
				if(!build){
					numtype last;
					for(int i = index; i < m_size; i++){
						if(i == index){
							last = m_ary[i];
						}
						else if(i > index){
							numtype temp = m_ary[i];
							m_ary[i] = last;
							last = temp;
						}
					}
				}
			}
			m_ary[index] = value;
		}
		/*
		* �Ƴ�����
		* @param index ����
		*/
		void removeAt(int index){
			m_size -= 1;
			for(int i = index;i < m_size; i++){
				m_ary[i] = m_ary[i + 1];
			}
			bool reduce = false;
            if(m_mode == 0){
                if(m_capacity > 4 && m_size > 0){
                    if(m_capacity > (int)(m_size * 1.5)){
                        m_capacity = (int)(m_size * 1.5);
                        reduce = true;
                    }
                }
            }
            else{
                if(m_capacity - m_size > m_step){
                    m_capacity -= m_step;
                    reduce = true;
                }
            }
			if(reduce){
				if(m_capacity > 0){
					if(m_mode == 0){
						numtype *newAry = new numtype[m_capacity];
						for(int i = 0;i < m_size; i++){
							newAry[i] = m_ary[i];
						}
						delete[] m_ary;
						m_ary = newAry;
					}
					else{
						numtype *newAry = (numtype*)VirtualAlloc(m_ary, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
						if(newAry){
							m_ary = newAry;
						}
						else{
							newAry = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
							MoveMemory(newAry, m_ary, sizeof(numtype) * m_size);
							VirtualFree(m_ary, 0, MEM_RELEASE);
							m_ary = newAry;
						}
					}
				}
				else{
					if(m_ary){
						if(m_mode == 0){
							delete[] m_ary;
						}
						else{
							VirtualFree(m_ary, 0, MEM_RELEASE);
						}
						m_ary = 0;
					}
				}
			}
		}
		/*
		* ��������
		* @param index ����
		* @param value ֵ
		*/
		void set(int index,numtype value){
			m_ary[index] = value;
		}
		/*
		* ��������
		* @param capacity ����
		*/
		void setCapacity(int capacity){
			m_capacity = capacity;
			if(m_ary){
				if(m_mode == 0){
					numtype *newAry = new numtype[m_capacity];
					for(int i = 0; i < m_size - 1; i++){
						newAry[i] = m_ary[i];
					}
					delete[] m_ary;
					m_ary = newAry;
				}
				else{
					numtype *newAry = (numtype*)VirtualAlloc(m_ary, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
					if(newAry){
						m_ary = newAry;
					}
					else{
						newAry = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE);
						MoveMemory(newAry, m_ary, sizeof(numtype) * (m_size - 1));
						VirtualFree(m_ary, 0, MEM_RELEASE);
						m_ary = newAry;
					}
				}
			}
		}
		/*
		* ���ò���
		* @param step ����
		*/
		void setStep(int step){
			m_step = step;
		}
		/*
		* ��ȡ�ߴ�
		* @param step �ߴ�
		*/
		int size(){
			return m_size;
		}
		/*
		* ��������
		*/
		virtual ~ArrayList(){
			clear();
		}
		/*
		* �������캯��
		*/
		ArrayList(const ArrayList& rhs){
            if (this != &rhs) {
                m_size = rhs.m_size;
                m_capacity = rhs.m_capacity;
                m_mode = rhs.m_mode;
                m_step = rhs.m_step;
                if(m_mode == 0){
                    m_ary = new numtype[m_capacity];
                }
                else{
                    m_ary = (numtype*)malloc(sizeof(numtype) * m_capacity);
                }
                for (int i = 0; i < m_size; i++){
                    m_ary[i] = rhs.m_ary[i];
                }
            }
        }
		/*
		* ��������
		*/
		const ArrayList& operator=(const ArrayList& rhs){
            if (this != &rhs) {
                clear();
                m_size = rhs.m_size;
                m_capacity = rhs.m_capacity;
                m_mode = rhs.m_mode;
                m_step = rhs.m_step;
				if(m_mode == 0){
					m_ary = new numtype[m_capacity];
				}
				else{
					m_ary = (numtype*)VirtualAlloc(0, sizeof(numtype) * m_capacity, MEM_COMMIT, PAGE_READWRITE); 
				}
                for (int i = 0; i < m_size; i++){
                    m_ary[i] = rhs.m_ary[i];
                }
            }
            return *this;
        }
	};

	/*
	* �Զ����ϣ��
	*/
	template <class KEY,class VALUE>
	class HashMap{
	private:
		/*
		* ��ȡint�Ĺ�ϣ
		*/
		int hashKey(int key){
			return key;
		}
		/*
		* ��ȡchar*�Ĺ�ϣ
		*/
		int hashKey(char* chPtr){
			int len = (int)strlen(chPtr);
			int hash = 0, offset = 0;
			int h = hash; 
			if (h == 0 && len > 0) {
				int off = offset; 
				for (int i = 0; i < len; i++) {
					h = 31 * h + chPtr[off++]; 							
				}
				hash = h;
			}
			return h;
		}
		/*
		* ��ȡstring�Ĺ�ϣ
		*/
		int hashKey(string key){
			return (char*)hashKey(key.c_str());
		}
		/*
		* ��ȡwstring�ϵĹ�ϣ
		*/
		int hashKey(wstring pKey){
			string sKey = FCStr::wstringTostring(pKey);
			const char *chPtr = sKey.c_str();
			int len = (int)strlen(chPtr);
			int hash = 0, offset = 0;
			int h = hash; 
			if (h == 0 && len > 0) {
				int off = offset; 
				for (int i = 0; i < len; i++) {
					h = 31 * h + chPtr[off++]; 							
				}
				hash = h;
			}
			return h;
		}
		/*
		* ��ȡdouble�Ĺ�ϣ
		*/
		int hashKey(double key){
			if (key == 0.0){
				return 0;
			}
			long num2 = *((long*) &key);
			return (((int) num2) ^ ((int) (num2 >> 0x20)));
		}
	protected:
		/*
		* ��ϣ�б�
		*/
		ArrayList<int> m_hashs;
		/*
		* �����б�
		*/
		ArrayList<KEY> m_keys;
		/*
		* ֵ���б�
		*/
		ArrayList<VALUE> m_rows;
		/*
		* ��ӹ�ϣֵ
		*/
		int addHashCode(int hashCode)
		{
			if(m_hashs.size() == 0 || hashCode > m_hashs.get((int)m_hashs.size() - 1)){
				m_hashs.add(hashCode);
				return m_hashs.size() - 1;
			}
			else{
				int begin = 0;
				int end = m_rows.size() - 1;
				int sub = end - begin;
				while(sub > 1){
					int half = begin + sub / 2;
					int hf = m_hashs.get(half);
					if(hf > hashCode){
						end = half;
					}
					else if(hf < hashCode){
						begin = half;
					}
					sub = end - begin;
				}
				if(hashCode < m_hashs.get(begin)){
					m_hashs.insert(begin, hashCode);
					return begin;
				}
				else if(hashCode > m_hashs.get(end)){
					m_hashs.insert(end + 1, hashCode);
					return end + 1;
				}
				else{
					m_hashs.insert(begin + 1, hashCode);
					return begin + 1;
				}
			}
			return -1;
		}
	public:
		/*
		* ���
		*/
		void clear(){
			m_hashs.clear();
			m_keys.clear();
			m_rows.clear();
		}
		/*
		* ���ݹ�ϣ������Ҽ�������
		*/
		int findKeyIndex(int hashCode){
			int low = 0;
			int high = m_hashs.size() - 1;
			while (low <= high) {
				int middle = (low + high) / 2;
				double hf = m_hashs.get(middle);
				if (hashCode == hf) {
					return middle;
				}
				else if (hashCode > hf) {
					low = middle + 1;
				}
				else if (hashCode < hf) {
					high = middle - 1;
				}
			}
			return -1;
		}
		/*
		* ���ݹ�ϣ������Ҽ��Ķ������
		*/
		void findKeyIndexs(int rowIndex, int hashCode, int *list, int *len){
			if(rowIndex != -1){
				int hSize = m_hashs.size();
				int tempIndex = rowIndex;
				while(tempIndex >= 0){
					if(m_hashs.get(tempIndex) == hashCode){
						list[*len] = tempIndex;
						*len = *len + 1;
					}
					else{
						break;
					}
					tempIndex--;
				}
				tempIndex = rowIndex + 1;
				while(tempIndex < hSize){
					if(m_hashs.get(tempIndex) == hashCode){
						list[*len] = tempIndex;
						*len = *len + 1;
					}
					else{
						break;
					}
					tempIndex++;
				}
			}
		}
		/*
		* �Ƿ������
		*/
		bool containsKey(KEY key){
			int hashCode = hashKey(key);
			int index = findKeyIndex(hashCode);
			if(index != -1){
				int list[1024];
				int len = 0;
				findKeyIndexs(index, hashCode, list, &len);
				if(len >= 1){
					for(int i = 0; i < len; i++){
						if(m_keys.get(list[i]) == key){
							index = list[i];
							break;
						}
					}
				}
				return true;
			}
			return false;
		}
		/*
		* ���ݼ���ȡֵ
		*/
		VALUE get(KEY key){
			int hashCode = hashKey(key);
			int index = findKeyIndex(hashCode);
			if(index != -1){
				int list[1024];
				int len = 0;
				findKeyIndexs(index, hashCode, list, &len);
				if(len >= 1){
					for(int i = 0; i < len; i++){
						if(m_keys.get(list[i]) == key){
							index = list[i];
							break;
						}
					}
				}
				return m_rows.get(index);
			}
			return 0;
		}
		/*
		* ����������ȡ��
		*/
		KEY getKey(int index){
			return m_keys.get(index);
		}
		/*
		* ����������ȡֵ
		*/
		VALUE getValue(int index){
			return m_rows.get(index);
		}
		/*
		* �����ֵ��
		*/
		void put(KEY key, VALUE value){
			int hashCode = hashKey(key);
			int index = findKeyIndex(hashCode);
			if(index == -1){
				index = addHashCode(hashCode);
			}
			else{
				int list[1024];
				int len = 0;
				findKeyIndexs(index, hashCode, list, &len);
				if(len >= 1){
					index =-1;
					for(int i = 0; i < len; i++){
						if(m_keys.get(list[i]) == key){
							index = list[i];
							break;
						}
					}
					if(index == -1){
						index = addHashCode(hashCode);
					}
				}
			}
			m_keys.insert(index, key);
			m_rows.insert(index, value);
		}
		/*
		* �Ƴ�
		*/
		void remove(KEY key){
			int hashCode = hashKey(key);
			int index = findKeyIndex(hashCode);
			if(index != -1){
				int list[1024];
				int len = 0;
				findKeyIndexs(index, hashCode, list, &len);
				if(len >= 1){
					index = -1;
					for(int i = 0; i < len; i++){
						if(m_keys.get(list[i]) == key){
							index = list[i];
							break;
						}
					}
				}
				if(index != -1){
					m_hashs.removeAt(index);
					m_keys.removeAt(index);
					m_rows.removeAt(index);
				}
			}
		}
		int size(){
			return m_hashs.size();
		}	
	public:
		/*
		* ���캯��
		*/
		HashMap(){}
		/*
		* ��������
		*/
		virtual ~HashMap(){clear();}
	public:
		/*
		* �������캯��
		*/
        HashMap(const HashMap& rhs){
            if (this != &rhs) {
                m_hashs = rhs.m_hashs;
                m_keys = rhs.m_keys;
                m_rows = rhs.m_rows;
            }
        }
		/*
		* ��д���ڷ���
		*/
        const HashMap& operator=(const HashMap& rhs){
            if (this != &rhs) {
                clear();
                m_hashs = rhs.m_hashs;
                m_keys = rhs.m_keys;
                m_rows = rhs.m_rows;
            }
            return *this;
        }
	};

	typedef POINT FCPoint;

	typedef SIZE FCSize;

	typedef RECT FCRect;

	struct FCAnchor{
	public:
	    /**
		 * �ײ�����
		 */
		bool bottom;
		/**
		 * �������
		 */
		bool left;
		/**
		 * �Ҳ�����
		 */
		bool right;
		/**
		 * �������
		 */
		bool top;
	    /**
         * ����ê����Ϣ
        */
		FCAnchor(){
			bottom = false;
			left = false;
			right = false;
			top = false;
		}
		/**
         * ����ê����Ϣ
         * @param left  ���
         * @param top   ����
         * @param right �Ҳ�
         * @param bottom    �ײ�
        */
		FCAnchor(bool left, bool top, bool right, bool bottom){
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
		}
	};

	/*
	* �ؼ����ݵĲ���
	*/
	enum FCContentAlignment{
        FCContentAlignment_BottomCenter, //�в����¾��ж���
        FCContentAlignment_BottomLeft, //���·�����
        FCContentAlignment_BottomRight, //���·�����
        FCContentAlignment_MiddleCenter, //��ֱ����
        FCContentAlignment_MiddleLeft, //��ֱ���п���
        FCContentAlignment_MiddleRight, //��ֱ���п���
        FCContentAlignment_TopCenter, //�в����Ͼ��ж���
        FCContentAlignment_TopLeft, //���Ϸ�����
        FCContentAlignment_TopRight //���Ϸ�����
	};

	/*
	* ���
	*/
	enum FCCursors{
		FCCursors_AppStarting, //��������
        FCCursors_Arrow, //��ͷ
        FCCursors_Cross, //ʮ����
        FCCursors_Hand, //����
		FCCursors_Help, //����
		FCCursors_IBeam, //�ı�������
		FCCursors_No, //��ǰ������Ч
        FCCursors_SizeAll, //�ĸ���ͷ
        FCCursors_SizeNESW, //�Խ��ߴ�С�������
        FCCursors_SizeNS, //˫��ֱ��С�������
        FCCursors_SizeNWSE, //˫��Խ��ߴ�С�������
        FCCursors_SizeWE, //˫��ˮƽ��С�������
		FCCursors_UpArrow, //���ϼ�ͷ
		FCCursors_WaitCursor //�ȴ�
	};

	/*
	* �ؼ��󶨱�Ե����
	*/
	enum FCDockStyle{
		FCDockStyle_Bottom, //�ײ�
		FCDockStyle_Fill, //���
		FCDockStyle_Left, //���
		FCDockStyle_None, //����
		FCDockStyle_Right, //�Ҳ�
		FCDockStyle_Top //����
	};

	/*
	* �ؼ��������з�ʽ
	*/
	enum FCHorizontalAlign{
		FCHorizontalAlign_Center, //����
		FCHorizontalAlign_Right, //Զ��
		FCHorizontalAlign_Inherit, //�̳�
		FCHorizontalAlign_Left //����
	};

	/*
	* �ؼ��������з�ʽ
	*/
	enum FCVerticalAlign{
		FCVerticalAlign_Bottom, //�ײ�
		FCVerticalAlign_Inherit, //�м�
		FCVerticalAlign_Middle, //�̳�
		FCVerticalAlign_Top //����
	};

	/*
	* �ؼ�������ʽ
	*/
	enum FCLayoutStyle{
		FCLayoutStyle_BottomToTop, //���¶���
		FCLayoutStyle_LeftToRight, //��������
		FCLayoutStyle_None, //�޲���
		FCLayoutStyle_RightToLeft, //��������
		FCLayoutStyle_TopToBottom //���϶���
	};

	/*
	* ����ģʽ
	*/
	enum FCMirrorMode{
		FCMirrorMode_BugHole, //�涴
		FCMirrorMode_None, //��
		FCMirrorMode_Shadow //Ӱ��
	};

    /**
	* ����ɫ
	*/
	static Long FCColor_Back = (Long)-200000000001;
	/**
	* ������ɫ
	*/
	static Long FCColor_Border = (Long)-200000000002;
	/**
	* ǰ��ɫ
    */
	static Long FCColor_Text = (Long)-200000000003;
	/**
	* �����õı���ɫ
	*/
    static Long FCColor_DisabledBack = (Long)-200000000004;
    /**
	* �����õ�ǰ��ɫ
	*/
    static Long FCColor_DisabledText = (Long)-200000000005;
    /**
	 * ������ͣ�ı���ɫ
	 */
	static Long FCColor_Hovered = (Long)-200000000006;
	/**
	 * ���������µı���ɫ
	 */
	static Long FCColor_Pushed = (Long)-200000000007;
	/**
	* ����ɫ
	*/
	static Long FCColor_None = (Long)-200000000000;

	class FCPaint;

	/*
	* ��ɫ��ʾ
	*/
	class FCColor{
	public:
		/*
		* ��ȡargbֵ
		*/
		static Long argb(int r, int g, int b);
	    /**
         * ��ȡRGB��ɫ
         * @param r ��ɫֵ
         * @param g ��ɫֵ
         * @param b ��ɫֵ
         * @returns RGB��ɫ
        */
		static Long argb(int a, int r, int g, int b);
	    /**
         * ��ȡRGB��ɫ
         * @param a  ͸��ֵ
        */
		static void toArgb(FCPaint *paint, Long dwPenColor, int *a, int *r, int *g, int *b);
	    /**
         * ��ȡ����ɫ
         * @param originalColor  ԭʼɫ
         * @param ratio  ����
        */
		static Long ratioColor(FCPaint *paint, Long originalColor, double ratio);
		/**
		 * ��ȡ��ɫ
		 */
		static Long reverse(FCPaint *paint, Long originalColor);
	};

	/*
	* �����
	*/
	struct FCPointF{
    /**
             * ��������
             * @param x ������
             * @param y ������
    */
	public:
		float x;
		float y;
	};

	/*
	* �ߴ�
	*/
	struct FCSizeF{
    /**
             * ���������ͳߴ�
             * @param cx ��
             * @param cy ��
             * @returns �ֶα���
    */
	public:
		float cx;
		float cy;
	};

	/*
	* ����
	*/
	struct FCRectF{
	/**
	* ��������
	*/
	public:
	    /**
		 * �������
		 */
		float left;
		/**
		 * ��������
		 */
		float top;
		/**
		 * �Ҳ�����
		 */
		float right;
		/**
		 * �ײ�����
		 */
		float bottom;
	};

	/*
	* ����
	*/
	class FCFont{
	public:
	    /**
		 * ����
		 */
		String m_fontFamily;
		/**
		 * �����С
		 */
		float m_fontSize;
		/**
		 * �Ƿ����
		 */
		bool m_bold;
		/**
		 * �Ƿ����»���
		 */
		bool m_underline;
		/**
		 * �Ƿ�б��
		 */
		bool m_italic;
		/**
		 * �Ƿ���ɾ����
		 */
		bool m_strikeout;
		/*
		* ��������
		*/
		FCFont(){
			m_fontFamily = L"Simsun";
			m_fontSize = 12;
			m_bold = false;
			m_underline = false;
			m_italic = false;
			m_strikeout = false;
		}
	    /**
         * ��������
         * @param  fontFamily ����
         * @param fontSize  �ֺ�
         * @param bold �Ƿ����
         * @param underline �Ƿ����»���
         * @param italic �Ƿ�б��
         * @param strikeout �Ƿ���ɾ����
        */
		FCFont(const String& fontFamily, float fontSize, bool bold, bool underline, bool italic){
			m_fontFamily = fontFamily;
			m_fontSize = fontSize;
			m_bold = bold;
			m_underline = underline;
			m_italic = italic;
			m_strikeout = false;
		}
	    /**
         * ��������
         * @param  fontFamily ����
         * @param fontSize  �ֺ�
         * @param bold �Ƿ����
         * @param underline �Ƿ����»���
         * @param italic �Ƿ�б��
         * @param strikeout �Ƿ���ɾ����
        */
		FCFont(const String& fontFamily, float fontSize, bool bold, bool underline, bool italic, bool strikeout){
			m_fontFamily = fontFamily;
			m_fontSize = fontSize;
			m_bold = bold;
			m_underline = underline;
			m_italic = italic;
			m_strikeout = strikeout;
		}
	public:
		/*
		* ��������
		*/
		void copy(FCFont *font){
			m_fontFamily = font->m_fontFamily;
			m_fontSize = font->m_fontSize;
			m_bold = font->m_bold;
			m_underline = font->m_underline;
			m_italic = font->m_italic;
			m_strikeout = font->m_strikeout;
		}
	};

	/*
	* �߾�
	*/
	struct FCPadding{
	public:
	    /**
		 * �ױ߾�
		 */
		int bottom;
		/**
		 * ��߾�
		 */
		int left;
		/**
		 * �ұ߾�
		 */
		int right;
		/**
		 * ���߾�
		 */
		int top;
		/**
		 * �����߾�
		 */
		FCPadding(){
			bottom = 0;
			left = 0;
			right = 0;
			top = 0;
		}
		/**
		 * �����߾�
		 */
		FCPadding(int all){
			bottom = all;
			left = all;
			right = all;
			top = all;
		}	
		/**
		 * �����߾�
		 */
		FCPadding(int left, int top, int right, int bottom){
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
		}
	};

	/*
	* ������Ϣ
	*/
    class FCTouchInfo{
    public:
		/*
		* �������
		*/
        int m_clicks;
        /**
		 * ����ֵ
		 */
        int m_delta;
        /**
		 * �Ƿ��һ������
		 */
        bool m_firstTouch;
        /**
		 * ��һ������
		 */
        FCPoint m_firstPoint;
        /**
		 * �Ƿ�ڶ�������
		 */
        bool m_secondTouch;
        FCPoint m_secondPoint;
    public:
		/*
		* ���캯��
		*/
        FCTouchInfo(){
            m_clicks = 0;
            m_delta = 0;
            m_firstTouch = false;
            m_firstPoint.x = 0;
            m_firstPoint.y = 0;
            m_secondTouch = false;
            m_secondPoint.x = 0;
            m_secondPoint.y = 0;
        }
		/*
		* ��������
		*/
        ~FCTouchInfo(){
        }
    };

	/*
	* ��ͼ
	*/
	class FCPaint{
	public:
		/*
		* ���캯��
		*/
		FCPaint();
		/*
		* ��������
		*/
		virtual ~FCPaint();
	public:
	    /**
         * �������
         * @param  rect ��������
         * @param startAngle �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ��ӱ���������
         * @param  point1  ����1
         * @param  point2  ����2
         * @param  point3  ����3
         * @param  point4  ����4
        */
		virtual void addBezier(FCPoint *apt, int cpt);
	    /**
         * �������
         * @param  points  ����
        */
		virtual void addCurve(FCPoint *apt, int cpt);
	    /**
         * �����Բ
         * @param  rect ����
        */
		virtual void addEllipse(const FCRect& rect);
	    /**
         * ���ֱ��
         * @param  x1 ��һ����ĺ�����
         * @param  y1 ��һ�����������
         * @param  x2 �ڶ�����ĺ�����
         * @param  y2 �ڶ������������
        */
		virtual void addLine(int x1, int y1, int x2, int y2);
	    /**
         * ��Ӿ���
         * @param  rect ����
        */
		virtual void addRect(const FCRect& rect);
	    /**
         * �������
         * @param  rect ��������
         * @param startAngle �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �������
         * @param  text ����
         * @param  font ����
         * @param  rect ����
        */
		virtual void addText(const wchar_t *strText, FCFont *font, const FCRect& rect);
		virtual void beginExport(const String& exportPath, const FCRect& rect);
	    /**
         * ��ʼ��ͼ
         * @param hdc  HDC
         * @param wRect ��������
         * @param pRect ˢ������
        */
		virtual void beginPaint(HDC hDC, const FCRect& wRect, const FCRect& pRect);
		/**
		 * ��ʼһ��·��
		 */
		virtual void beginPath();
		/**
		 * �������
		 */
		virtual void clearCaches();
		/**
		 * �ü�·��
		 */
		virtual void clipPath();
		/**
		 * �պ�·��
		 */
		virtual void closeFigure();
		/**
		 * ����һ��·��
		 */
		virtual void closePath();
	    /**
         * ���ƻ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ñ���������
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param points  ������
        */
		virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ��������
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param points  ������
        */
		virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  left �������
         * @param  top  �������
         * @param  right �Ҳ�����
         * @param  bottom  �ײ�����
        */
		virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ����ͼƬ
         * @param  imagePath  ͼƬ·��
         * @param  rect   ��������
        */
		virtual void drawImage(const wchar_t *imagePath, const FCRect& rect);
	    /**
         * ����ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  x1 ��һ����ĺ�����
         * @param  y1 ��һ�����������
         * @param  x2 �ڶ�����ĺ�����
         * @param  y2 �ڶ������������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
	    /**
         * ����ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  x ��һ��������
         * @param  y �ڶ����������
        */
		virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
	    /**
         * ����·��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
        */
		virtual void drawPath(Long dwPenColor, float width, int style);
	    /**
         * ���ƻ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * ���ƶ����
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  points  �������
        */
		virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƴ���ֱ��
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  points  �㼯
        */
		virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
        */
		virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
	    /**
         * ���ƾ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  left �������
         * @param  top  �������
         * @param  right �Ҳ�����
         * @param  bottom  �ײ�����
        */
		virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
	    /**
         * ����Բ�Ǿ���
         * @param  dwPenColor ��ɫ
         * @param  width  ���
         * @param  style  ��ʽ
         * @param  rect   ��������
         * @param  cornerRadius �߽ǰ뾶
        */
		virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
	    /**
         * ���ƾ���
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawText(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRect& rect);
	    /**
         * ���ƾ���
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawText(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRectF& rect);
	    /**
         * �����Զ�ʡ�Խ�β������
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void drawTextAutoEllipsis(const wchar_t *strText, Long dwPenColor, FCFont *font, const FCRect& rect);
		/**
		 * ��������
		 */
		virtual void endExport();
		/**
		 * ������ͼ
		 */
		virtual void endPaint();
		/*
		* ȥ���ü�·��
		*/
		virtual void excludeClipPath();
	    /**
         * �����Բ
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
        */
		virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
	    /**
         * ���ƽ�����Բ
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  rect     ����
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
		/*
		* ���ƽ�������
		*/
		virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
	    /**
         * ��佥��·��
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  points   ��ļ���
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
	    /**
         * ���ƽ������
         * @param  dwFirst  ��ʼ��ɫ
         * @param  dwSecond ������ɫ
         * @param  rect     ����
         * @param  cornerRadius     Բ�ǰ뾶
         * @param  angle    �Ƕ�
        */
		virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
	    /**
         * ���·��
         * @param  dwPenColor ��ɫ
        */
		virtual void fillPath(Long dwPenColor);
	    /**
         * ��������
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
         * @param  startAngle  �� x �ᵽ���ߵ���ʼ����˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
         * @param sweepAngle   �� startAngle ���������ߵĽ�������˳ʱ�뷽������Ľǣ��Զ�Ϊ��λ��
        */
		virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
	    /**
         * �����Բ
         * @param  dwPenColor ��ɫ
         * @param  points     �������
        */
		virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
	    /**
         * ������
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
        */
		virtual void fillRect(Long dwPenColor, const FCRect& rect);
	    /**
         * ������
         * @param  text   ����
         * @param  dwPenColor ��ɫ
         * @param  font   ����
         * @param  rect   ��������
        */
		virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
	    /**
         * ���Բ�Ǿ���
         * @param  dwPenColor ��ɫ
         * @param  rect   ��������
         * @param  cornerRadius �߽ǰ뾶
        */
		virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
	    /**
         * ��ȡ��ɫ
         * @param  dwPenColor ������ɫ
         * @returns   �����ɫ
        */
		virtual Long getColor(Long dwPenColor);
	    /**
         * ��ȡҪ���Ƶ���ɫ
         * @param  dwPenColor ������ɫ
         * @returns   �����ɫ
        */
		virtual Long getPaintColor(Long dwPenColor);
		/**
		 * ��ȡƫ��
		 */
		virtual FCPoint getOffset();
	    /**
         * ��ת�Ƕ�
         * @param  op   Բ������
         * @param  mp   �������
         * @param  angle  �Ƕ�
         * @returns  �������
        */
		virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
	    /**
         * ���òü�����
         * @param  rect   ����
        */
		virtual void setClip(const FCRect& rect);
	    /**
         * ����ֱ�����˵���ʽ
         * @param  startLineCap  ��ʼ����ʽ
         * @param  endLineCap  ��������ʽ
        */
		virtual void setLineCap(int startLineCap, int endLineCap);
	    /**
         * ����ƫ��
         * @param  mp  ƫ������
        */
		virtual void setOffset(const FCPoint& offset);
	    /**
         * ����͸����
         * @param  opacity  ͸����
        */
		virtual void setOpacity(float opacity);
	    /**
         * ������Դ��·��
         * @param  resourcePath  ��Դ��·��
        */
        virtual void setResourcePath(const String& resourcePath);
        /**
         * ������ת�Ƕ�
         * @param  rotateAngle  ��ת�Ƕ�
        */
		virtual void setRotateAngle(int rotateAngle);
	    /**
         * ������������
         * @param  scaleFactorX   ��������
         * @param  scaleFactorY   ��������
        */
		virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
	    /**
         * ����ƽ��ģʽ
         * @param  smoothMode  ƽ��ģʽ
        */
		virtual void setSmoothMode(int smoothMode);
	    /**
         * �������ֵ�����
         * @param  textQuality  ��������
        */
		virtual void setTextQuality(int textQuality);
	    /**
         * �����Ƿ�֧��͸��ɫ
         * @returns  �Ƿ�֧��
        */
		virtual bool supportTransparent();
	    /**
         * ��ȡ���ִ�С
         * @param  text   ����
         * @param  font   ����
         * @returns  �����С
        */
		virtual FCSize textSize(const wchar_t *strText, FCFont *font);
	    /**
         * ��ȡ���ִ�С
         * @param  text   ����
         * @param  font   ����
         * @returns  �����С
        */
		virtual FCSizeF textSizeF(const wchar_t *strText, FCFont *font);
	};
}

#endif