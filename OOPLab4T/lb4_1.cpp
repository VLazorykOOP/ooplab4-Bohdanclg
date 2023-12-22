#include <iostream>


class VectorUShort{
    unsigned short* data;
    int num;
    int state;

    public:

    VectorUShort();
    VectorUShort(int n);
    VectorUShort(int n, double value);
    VectorUShort(const VectorUShort& other);

    ~VectorUShort(){
        delete[] data;
    }

    friend VectorUShort operator++(VectorUShort& obj); //префіксна
    friend VectorUShort operator++(VectorUShort& obj, int); //постфіксна
    friend VectorUShort operator--(VectorUShort& obj);
    friend VectorUShort operator--(VectorUShort& obj, int);
    friend VectorUShort operator!(const VectorUShort& obj);
    friend VectorUShort operator~(const VectorUShort& obj);
    friend VectorUShort operator-(const VectorUShort& obj);

    VectorUShort& operator=(const VectorUShort& other);
    VectorUShort& operator+=(const VectorUShort& other);
    VectorUShort& operator-=(const VectorUShort& other);
    VectorUShort& operator*=(int scalar);
    VectorUShort& operator/=(int scalar);
    VectorUShort& operator%=(int scalar);
    VectorUShort& operator|=(const VectorUShort& other);
    VectorUShort& operator^=(const VectorUShort& other);
    VectorUShort& operator&=(const VectorUShort& other);

    friend VectorUShort operator+(const VectorUShort& v1, const VectorUShort& v2);
    friend VectorUShort operator-(const VectorUShort& v1, const VectorUShort& v2);
    friend VectorUShort operator*(const VectorUShort& v, double scalar);
    friend VectorUShort operator/(const VectorUShort& v, double scalar);
    friend VectorUShort operator%(const VectorUShort& v, double scalar);   

    friend VectorUShort operator|(const VectorUShort& v1, const VectorUShort& v2);
    friend VectorUShort operator^(const VectorUShort& v1, const VectorUShort& v2);
    friend VectorUShort operator&(const VectorUShort& v1, const VectorUShort& v2);

    friend std::istream& operator>>(std::istream& is, VectorUShort& v);
    friend std::ostream& operator<<(std::ostream& os, const VectorUShort& v);

    friend bool operator==(const VectorUShort& v1, const VectorUShort& v2);
    friend bool operator!=(const VectorUShort& v1, const VectorUShort& v2);

    unsigned short& operator[](int index);

    friend bool operator>(const VectorUShort& v1, const VectorUShort& v2);
    friend bool operator>=(const VectorUShort& v1, const VectorUShort& v2);
    friend bool operator<(const VectorUShort& v1, const VectorUShort& v2);
    friend bool operator<=(const VectorUShort& v1, const VectorUShort& v2);

};

VectorUShort::VectorUShort(){

    num = 1;
    state = 0;

    data = new unsigned short[1]();
    data[0] = 0.0;
}

VectorUShort::VectorUShort(int n){
       
    num = n;
    state = 0;

    data = new unsigned short[n]();

    for(int i = 0; i < n; ++i){
        data[i] = 0.0;
    }

}


VectorUShort::VectorUShort(int n, double value) : VectorUShort(n){

    num = n;
    state = 0;

    for(int i = 0; i < n; ++i){
        data[i] = value;
    }

}

VectorUShort::VectorUShort(const VectorUShort& other){
    num = other.num;
    state = other.state;
    data = new unsigned short[num]();

    for (int i = 0; i < num; ++i){
        data[i] = other.data[i];
    }
}

VectorUShort operator++(VectorUShort& obj){

    for (int i = 0; i < obj.num; ++i){
        ++obj.data[i];
    }
    return obj;

}

VectorUShort operator++(VectorUShort& obj, int){

    VectorUShort temp(obj);
    ++obj;
    return temp;

}

VectorUShort operator--(VectorUShort& obj){

    for (int i = 0; i < obj.num; ++i){
        --obj.data[i];
    }
    return obj;

}

VectorUShort operator--(VectorUShort& obj, int){

    VectorUShort temp(obj);
    --obj;
    return temp;

}

VectorUShort operator!(const VectorUShort& obj){

     return obj.num != 0;

}

VectorUShort operator~(const VectorUShort& obj){

    VectorUShort result(obj.num);
    for (int i = 0; i < obj.num; ++i){
        result.data[i] = ~obj.data[i];
    }
    return result;

}

VectorUShort operator-(const VectorUShort& obj){

    VectorUShort result(obj);
    for (int i = 0; i < obj.num; ++i) {
        result.data[i] = -obj.data[i];
    }
    return result;

}

VectorUShort& VectorUShort::operator=(const VectorUShort& other){

    if (this != &other){

        delete[] data;


        num = other.num;
        state = other.state;
        data = new unsigned short[num];
        for (int i = 0; i < num; ++i){
            data[i] = other.data[i];
        }
    }

    return *this;
}

VectorUShort& VectorUShort::operator+=(const VectorUShort& other){

    if (num == other.num){
        for (int i = 0; i < num; ++i){
            data[i] += other.data[i];
        }
    }
    return *this;

}

VectorUShort& VectorUShort::operator-=(const VectorUShort& other){

    if (num == other.num){
        for (int i = 0; i < num; ++i){
            data[i] -= other.data[i];
        }
    }
    return *this;

}
VectorUShort& VectorUShort::operator*=(int scalar){

    for (int i = 0; i < num; ++i){
        data[i] *= scalar;
    }
    return *this;

}
VectorUShort& VectorUShort::operator/=(int scalar){

    if (scalar != 0){
        for (int i = 0; i < num; ++i){
            data[i] /= scalar;
        }
    }
    return *this;

}

VectorUShort& VectorUShort::operator%=(int scalar){
    
    if (scalar != 0){
        for (int i = 0; i < num; ++i){
            data[i] %= scalar;
        }
    }
    return *this;

}

VectorUShort& VectorUShort::operator|=(const VectorUShort& other){

    if (num == other.num){
        for (int i = 0; i < num; ++i){
            data[i] |= other.data[i];
        }
    }
    return *this;

}

VectorUShort& VectorUShort::operator^=(const VectorUShort& other){

    if (num == other.num){
        for (int i = 0; i < num; ++i){
            data[i] ^= other.data[i];
        }
    }
    return *this;

}

VectorUShort& VectorUShort::operator&=(const VectorUShort& other){

    if (num == other.num){
        for (int i = 0; i < num; ++i){
            data[i] &= other.data[i];
        }
    }
    return *this;

}

VectorUShort operator+(const VectorUShort& v1, const VectorUShort& v2){

    VectorUShort result(v1);
    result += v2;
    return result;

}

VectorUShort operator-(const VectorUShort& v1, const VectorUShort& v2){

    VectorUShort result(v1);
    result -= v2;
    return result;

}

VectorUShort operator*(const VectorUShort& v, double scalar){

    VectorUShort result(v);
    result *= scalar;
    return result;

}

VectorUShort operator/(const VectorUShort& v, double scalar){

    VectorUShort result(v);
    result /= scalar;
    return result;

}

VectorUShort operator%(const VectorUShort& v, double scalar){

    VectorUShort result(v);
    if (scalar != 0) {
        for (int i = 0; i < result.num; ++i) {
            result.data[i] = static_cast<unsigned short>(result.data[i] % static_cast<unsigned short>(scalar));
        }
    }
    return result;

}

VectorUShort operator|(const VectorUShort& v1, const VectorUShort& v2){

    VectorUShort result(v1);
    result |= v2;
    return result;

}

VectorUShort operator^(const VectorUShort& v1, const VectorUShort& v2){

    VectorUShort result(v1);
    result ^= v2;
    return result;

}

VectorUShort operator&(const VectorUShort& v1, const VectorUShort& v2){

    VectorUShort result(v1);
    result &= v2;
    return result;

}

std::istream& operator>>(std::istream& is, VectorUShort& v){

    for (int i = 0; i < v.num; ++i){
        is >> v.data[i];
    }
    return is;

}

std::ostream& operator<<(std::ostream& os, const VectorUShort& v){

    for (int i = 0; i < v.num; ++i){
        os << v.data[i] << " ";
    }
    return os;

}

bool operator==(const VectorUShort& v1, const VectorUShort& v2){

    if (v1.num != v2.num){
        return false;
    }

    for (int i = 0; i < v1.num; ++i){
        if (v1.data[i] != v2.data[i]){
            return false;
        }
    }

    return true;

}

bool operator!=(const VectorUShort& v1, const VectorUShort& v2){

    return !(v1 == v2);

}

unsigned short& VectorUShort::operator[](int index){

    if(index >= 0 || index <num){
        return data[index];
    }

    else{
        return data[0];
    }

}

bool operator>(const VectorUShort& v1, const VectorUShort& v2){

    if (v1.num != v2.num){
        return v1.num > v2.num;
    }

    for (int i = 0; i < v1.num; ++i) {
        if (v1.data[i] <= v2.data[i]) {
            return false;
        }
    }

    return true;

}

bool operator>=(const VectorUShort& v1, const VectorUShort& v2){

    return (v1 > v2) || (v1 == v2);

}

bool operator<(const VectorUShort& v1, const VectorUShort& v2){

    return !(v1 >= v2);

}

bool operator<=(const VectorUShort& v1, const VectorUShort& v2){

    return !(v1 > v2);

}





int main() {
    VectorUShort v1; 
    VectorUShort v2(5); 
    VectorUShort v3(3, 42.0); 


    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;

    VectorUShort v4 = ++v1; 
    VectorUShort v5 = v2++; 
    VectorUShort v6 = --v3;
    VectorUShort v7 = v3--;

    std::cout << "++v1: " << v4 << std::endl;
    std::cout << "v2++: " << v5 << std::endl;
    std::cout << "--v3: " << v6 << std::endl;
    std::cout << "v3--: " << v7 << std::endl;

    VectorUShort v8(5, 10.0);
    VectorUShort v9(5, 30.0);

    std::cout << "v8: " << v8 << std::endl;
    std::cout << "v9: " << v9 << std::endl;

    std::cout << "!v8: " << !v8 << std::endl;
    std::cout << "~v9: " << ~v9 << std::endl;
    std::cout << "-v8: " << -v8 << std::endl;
    
    std::cout << "v8: " << v8 << std::endl;
    std::cout << "v9: " << v9 << std::endl;

    std::cout << "v8 == v9: " << (v8 == v9) << std::endl;
    std::cout << "v8 != v9: " << (v8 != v9) << std::endl;
    std::cout << "v8 > v9: " << (v8 > v9) << std::endl;
    std::cout << "v8 >= v9: " << (v8 >= v9) << std::endl;
    std::cout << "v8 < v9: " << (v8 < v9) << std::endl;
    std::cout << "v8 <= v9: " << (v8 <= v9) << std::endl;

    v8 += v9;
    std::cout << "v8 += v9: " << v8 << std::endl;
    v8 -= v9;
    std::cout << "v9 -= v8: " << v8 << std::endl;
    v8 *= 2;
    std::cout << "v8 *= 2: " << v8 << std::endl;
    v9 /= 2;
    std::cout << "v9 /= 2: " << v9 << std::endl;
    v8 %= 3;
    std::cout << "v8 %= 3: " << v8 << std::endl;
    v9 |= v8;
    std::cout << "v9 |= v8: " << v9 << std::endl;
    v8 ^= v9;
    std::cout << "v8 ^= v9: " << v8 << std::endl;
    v9 &= v8;
    std::cout << "v9 &= v8: " << v9 << std::endl;

    return 0;
}
