#include "testutil.h"
#include <npk.h>
#include <npk_dev.h>

int npk_06_sync_04( int argc, char * argv [] )
{
    system( "mkdir sync_test_04" );
    system( "mkdir sync_test_04/nested" );
    system( "cp sample2.txt sync_test_04/add1.txt" );
    system( "cp sample2.txt sync_test_04/add2.test" );
    system( "cp sample2.txt sync_test_04/nested/add3.tmp" );

    system( "../npk test.npk -create -sync sync_test_04 --sa -flag '*.txt@C' 'add2*@E' '*add3.tmp@C@E' --v --f --k 1:2:3:4" );

    int teakey[4] = {1,2,3,4};
    NPK_PACKAGE pack = npk_package_open( "test.npk", teakey );

    CHECK( pack != NULL );

    NPK_ENTITY entity;
    NPK_FLAG flag;

    entity = npk_package_get_entity( pack, "add1.txt" );
    CHECK( entity != NULL );
    npk_entity_get_current_flag( entity, &flag );
    CHECK( flag & ( NPK_ENTITY_COMPRESS ) ) 

    entity = npk_package_get_entity( pack, "add2.test" );
    CHECK( entity != NULL );
    npk_entity_get_current_flag( entity, &flag );
    CHECK( flag & ( NPK_ENTITY_ENCRYPT ) ) 

    entity = npk_package_get_entity( pack, "nested/add3.tmp" );
    CHECK( entity != NULL );
    npk_entity_get_current_flag( entity, &flag );
    CHECK( flag & ( NPK_ENTITY_ENCRYPT | NPK_ENTITY_COMPRESS ) ) 

    npk_package_close( pack );

    return 0;
}