#include "adios_bp_v1.h"
#include "adios_types.h"

#define BP_MAX_RANK 32
#define BP_MAX_NDIMS (BP_MAX_RANK+1)

struct bp_index_pg_struct_v1
{   
    char * group_name;
    enum ADIOS_FLAG adios_host_language_fortran;
    uint32_t process_id; 
    char * time_index_name;
    uint32_t time_index;
    uint64_t offset_in_file;

    struct bp_index_pg_struct_v1 * next;
};

struct bp_minifooter {
	uint64_t time_steps;
	uint64_t pgs_count;
	uint64_t pgs_length;
	uint16_t vars_count;
	uint64_t vars_length;
	uint64_t attrs_count;
	uint64_t attrs_length;
	uint64_t pgs_index_offset;
	uint64_t vars_index_offset;
	uint64_t attrs_index_offset;
	uint32_t version;
	uint64_t file_size;
} __attribute__((__packed__));

struct BP_FILE {
	MPI_File mpi_fh;
	MPI_Comm comm;
	struct adios_bp_buffer_struct_v1 * b;
	struct bp_index_pg_struct_v1 * pgs_root;
	struct adios_index_var_struct_v1 * vars_root;
	struct adios_index_attribute_struct_v1 * attrs_root;
	struct bp_minifooter mfooter; 
	struct BP_GROUP_VAR * gh;
};

struct BP_GROUP_VAR {
	uint16_t group_count;
	uint16_t group_id; 
	char ** namelist;
	uint32_t *** time_index; 
	uint64_t * pg_offsets;
	char ** var_namelist;
	uint16_t * var_counts_per_group;
	uint64_t ** var_offsets;
};

struct BP_GROUP {
	uint16_t group_id;
	uint16_t offset;
	uint16_t count;
	struct BP_FILE * fh;
	struct adios_index_var_struct_v1 * var_current;
};

