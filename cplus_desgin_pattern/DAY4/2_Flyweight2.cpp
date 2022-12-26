#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:

	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	static std::map<std::string, Image*> image_map;

	// �ڽ��� ��ü�� ����� static ��� �Լ�
	static Image* Create(const std::string& url)
	{
		Image* img = nullptr;
		
		auto ret = image_map.find(url);

		if (ret == image_map.end())
		{
			img = new Image(url);

			image_map[url] = img;
		}
		else
		{
			img = ret->second; // map �� �ݺ��ڴ� pair �� ������
		}

		return img;
	}
};
std::map<std::string, Image*> Image::image_map;




int main()
{
	// IOS ���߽� ���Ǵ� "cocoa" ���̺귯����
	// "UImage" ��ü ������ "static ����Լ�"�� ����ϵ��� �Ǿ� �ֽ��ϴ�
	// => ���� �׸��� �����ϰ� �˴ϴ�.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();
}

// ���� : map ���� Ű�� ���� ����� �Ʒ�ó�� ���� ������
// if ( image_map[url] == nullptr )

// �Ʒ� ó���ؾ� �մϴ�.
// auto ret = image_map.find(url);
// if ( ret == image_map.end()) {}

// C++20 ���ʹ� �Ʒ� ó�� �����մϴ�. - contain() ��� �Լ� �߰��ƽ��ϴ�.
// if ( image_map.contain(url) ) {}



