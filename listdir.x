const MAXLEN = 255;
typedef string nametype<MAXLEN>; 
typedef struct namenode* namelist;

/* a node in the directory list*/ 
struct namenode{
	nametype name;
	namelist next; 
};

/*result of a readdir operation*/ 
union readdir_ret switch (int err) {
	case 0:
		namelist list; /*no error, return directory entries as a linked list*/
	default:
		void; /*error occured, nothing returned*/
};

/*IDL program*/
program DIR_LIST_PROG {
	version DIR_LIST_VERS {
		readdir_ret READDIR(nametype) = 1;
	} = 1;
} = 0x30000087; 

