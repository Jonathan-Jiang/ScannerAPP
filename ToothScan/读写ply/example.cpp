

#include "plyio.h"

int main(int argc, char *argv[])
{
	orth::MeshModel mm;
	tinyply::plyio io;



	
	//��ply�ļ� �����ļ��������ģ���ļ�
	//read_ply_file("example_cube-binary.ply");
	io.read_ply_file(argv[1], mm);

	//дply�ļ� �����ļ���������ģ���ļ��������Ƿ������д�ı�ʶ
	//write_ply_example("example_cube");
	io.write_ply_example(argv[2], mm,false );
	
    return EXIT_SUCCESS;
}
