#include "global.h"
#include "helper.h"

void print_usage() {
	printf("[usage]:\n");
	printf("\t-nidINT       ; NODE_ID\n");
	printf("\t-pINT       ; PART_CNT\n");
	printf("\t-nINT       ; NODE_CNT\n");
	printf("\t-cnINT       ; CLIENT_NODE_CNT\n");

	printf("\t-vINT       ; VIRTUAL_PART_CNT\n");

	printf("\t-tINT       ; THREAD_CNT\n");
	printf("\t-trINT       ; REM_THREAD_CNT\n");
	printf("\t-tsINT       ; SEND_THREAD_CNT\n");
	printf("\t-ctINT       ; CLIENT_THREAD_CNT\n");
	printf("\t-ctrINT       ; CLIENT_REM_THREAD_CNT\n");
	printf("\t-ctsINT       ; CLIENT_SEND_THREAD_CNT\n");

	printf("\t-tppINT       ; MAX_TXN_PER_PART\n");
	printf("\t-tifINT       ; MAX_TXN_IN_FLIGHT\n");
	printf("\t-mprINT       ; MPR\n");
	printf("\t-doneINT       ; DONE_TIMER\n");
	printf("\t-progINT       ; PROG_TIMER\n");
	printf("\t-abrtINT       ; ABORT_PENALTY (ms)\n");

	printf("\t-qINT       ; QUERY_INTVL\n");
	printf("\t-dINT       ; PRT_LAT_DISTR\n");
	printf("\t-aINT       ; PART_ALLOC (0 or 1)\n");
	printf("\t-mINT       ; MEM_PAD (0 or 1)\n");
//	printf("\t-GcINT      ; CENTRAL_MAN\n");
//	printf("\t-GtINT      ; TS_ALLOC\n");
//	printf("\t-GkINT      ; KEY_ORDER\n");
//	printf("\t-GnINT      ; NO_DL\n");
//	printf("\t-GoINT      ; TIMEOUT\n");
//	printf("\t-GlINT      ; DL_LOOP_DETECT\n");

//	printf("\t-GbINT      ; TS_BATCH_ALLOC\n");
//	printf("\t-GuINT      ; TS_BATCH_NUM\n");
	
	printf("\t-o STRING   ; output file\n");
	printf("\t-i STRING   ; input file\n");
	printf("\t-cf STRING   ; txn file\n");
  /*
	printf("------ Migration ----\n");
	printf("\t-MeINT      ; HW_MIGRATE\n");
  */
	printf("  [YCSB]:\n");
//	printf("\t-cINT     ; CC_ALG (1:NO_WAIT, 2:WAIT_DIE, 3:DL_DETECT, 4:TIMESTAMP, 5:MVCC, 6:HSTORE)\n");
	printf("\t-dpFLOAT       ; DATA_PERC\n");
	printf("\t-apFLOAT       ; ACCESS_PERC\n");
	printf("\t-pptINT       ; PART_PER_TXN\n");
	printf("\t-eINT       ; PERC_MULTI_PART\n");
	//printf("\t-rFLOAT     ; READ_PERC\n");
	printf("\t-wFLOAT     ; WRITE_PERC\n");
	printf("\t-zipfFLOAT     ; ZIPF_THETA\n");
	printf("\t-sINT       ; SYNTH_TABLE_SIZE\n");
	printf("\t-rpqINT       ; REQ_PER_QUERY\n");
	printf("\t-fINT       ; FIELD_PER_TUPLE\n");
	printf("  [TPCC]:\n");
	printf("\t-whINT       ; NUM_WH\n");
	printf("\t-ppFLOAT    ; PERC_PAYMENT\n");
	printf("\t-upINT      ; WH_UPDATE\n");
  /*
	printf("  [TEST]:\n");
	printf("\t-Ar         ; Test READ_WRITE\n");
	printf("\t-Ac         ; Test CONFLIT\n");
  */
}

void parser(int argc, char * argv[]) {

	for (int i = 1; i < argc; i++) {
		assert(argv[i][0] == '-');
    if (argv[i][1] == 'd' && argv[i][2] == 'o' && argv[i][3] == 'n' && argv[i][4] == 'e')
      g_done_timer = atoi( &argv[i][5] );
    else if (argv[i][1] == 'p' && argv[i][2] == 'r' && argv[i][3] == 'o' && argv[i][4] == 'g')
			g_thread_cnt = atoi( &argv[i][5] );
    else if (argv[i][1] == 'a' && argv[i][2] == 'b' && argv[i][3] == 'r' && argv[i][4] == 't')
			g_abort_penalty = atoi( &argv[i][5] );
    else if (argv[i][1] == 'z' && argv[i][2] == 'i' && argv[i][3] == 'p' && argv[i][4] == 'f')
			g_zipf_theta = atoi( &argv[i][5] );
    else if (argv[i][1] == 'n' && argv[i][2] == 'i' && argv[i][3] == 'd')
			g_node_id = atoi( &argv[i][4] );
    else if (argv[i][1] == 'c' && argv[i][2] == 't' && argv[i][3] == 'r')
			g_client_rem_thread_cnt = atoi( &argv[i][4] );
    else if (argv[i][1] == 'c' && argv[i][2] == 't' && argv[i][3] == 's')
			g_client_send_thread_cnt = atoi( &argv[i][4] );
    else if (argv[i][1] == 't' && argv[i][2] == 'p' && argv[i][3] == 'p')
			g_max_txn_per_part = atoi( &argv[i][4] );
    else if (argv[i][1] == 't' && argv[i][2] == 'i' && argv[i][3] == 'f')
			g_inflight_max = atoi( &argv[i][4] );
    else if (argv[i][1] == 'm' && argv[i][2] == 'p' && argv[i][3] == 'r')
			g_mpr = atoi( &argv[i][4] );
    else if (argv[i][1] == 'p' && argv[i][2] == 'p' && argv[i][3] == 't')
      g_part_per_txn = atoi( &argv[i][4] );
    else if (argv[i][1] == 'r' && argv[i][2] == 'p' && argv[i][3] == 'q')
      g_req_per_query = atoi( &argv[i][4] );
    else if (argv[i][1] == 'c' && argv[i][2] == 'n')
      g_client_node_cnt = atoi( &argv[i][3] );
    else if (argv[i][1] == 't' && argv[i][2] == 'r')
      g_rem_thread_cnt = atoi( &argv[i][3] );
    else if (argv[i][1] == 't' && argv[i][2] == 's')
      g_send_thread_cnt = atoi( &argv[i][3] );
    else if (argv[i][1] == 'c' && argv[i][2] == 't')
      g_client_thread_cnt = atoi( &argv[i][3] );
    else if (argv[i][1] == 'w' && argv[i][2] == 'h')
      g_num_wh = atoi( &argv[i][3] );
    else if (argv[i][1] == 'c' && argv[i][2] == 'f')
			txn_file = argv[++i];
    else if (argv[i][1] == 'p' && argv[i][2] == 'p')
      g_perc_payment = atof( &argv[i][3] );
    else if (argv[i][1] == 'u' && argv[i][2] == 'p')
      g_wh_update = atoi( &argv[i][3] );
    else if (argv[i][1] == 'd' && argv[i][2] == 'p')
      g_data_perc = atof( &argv[i][3] );
    else if (argv[i][1] == 'a' && argv[i][2] == 'p')
      g_access_perc = atof( &argv[i][3] );
    else if (argv[i][1] == 't'&& argv[i][2] == 'w') {
			g_txn_write_perc = atof( &argv[i][2] );
			g_txn_read_perc = 1.0 - atof( &argv[i][2] );
    }
    else if (argv[i][1] == 'p')
      g_part_cnt = atoi( &argv[i][2] );
    else if (argv[i][1] == 'n')
      g_node_cnt = atoi( &argv[i][2] );
    else if (argv[i][1] == 't')
			g_thread_cnt = atoi( &argv[i][2] );
    else if (argv[i][1] == 'q')
			g_query_intvl = atoi( &argv[i][2] );
    else if (argv[i][1] == 'd')
			g_prt_lat_distr = atoi( &argv[i][2] );
    else if (argv[i][1] == 'a')
			g_part_alloc = atoi( &argv[i][2] );
    else if (argv[i][1] == 'm')
			g_mem_pad = atoi( &argv[i][2] );
    else if (argv[i][1] == 'o')
			output_file = argv[++i];
    else if (argv[i][1] == 'i')
			input_file = argv[++i];
    else if (argv[i][1] == 'e')
			g_perc_multi_part = atof( &argv[i][2] );
    /*
    else if (argv[i][1] == 'r')
			g_read_perc = atof( &argv[i][2] );
			g_write_perc = 1.0 - atof( &argv[i][2] );
      */
    else if (argv[i][1] == 'w') {
			g_tup_write_perc = atof( &argv[i][2] );
			g_tup_read_perc = 1.0 - atof( &argv[i][2] );
    }
    else if (argv[i][1] == 's')
			g_synth_table_size = atoi( &argv[i][2] );
    else if (argv[i][1] == 'f')
			g_field_per_tuple = atoi( &argv[i][2] );
		else if (argv[i][1] == 'h') {
			print_usage();
			exit(0);
		} else {
      printf("%s\n",argv[i]);
      fflush(stdout);
			assert(false);
    }
	}

    //g_inflight_max = g_inflight_max / g_node_cnt;
      printf("CC Alg %d\n",CC_ALG);
      printf("g_done_timer %ld\n",g_done_timer);
			printf("g_thread_cnt %d\n",g_thread_cnt );
			printf("g_abort_penalty %ld\n",g_abort_penalty); 
			printf("g_zipf_theta %f\n",g_zipf_theta );
			printf("g_node_id %d\n",g_node_id );
			printf("g_client_rem_thread_cnt %d\n",g_client_rem_thread_cnt );
			printf("g_client_send_thread_cnt %d\n",g_client_send_thread_cnt );
			printf("g_max_txn_per_part %d\n",g_max_txn_per_part );
			printf("g_inflight_max %d\n",g_inflight_max );
			printf("g_mpr %f\n",g_mpr );
      printf("g_part_per_txn %d\n",g_part_per_txn );
      printf("g_req_per_query %d\n",g_req_per_query );
      printf("g_client_node_cnt %d\n",g_client_node_cnt );
      printf("g_rem_thread_cnt %d\n",g_rem_thread_cnt );
      printf("g_send_thread_cnt %d\n",g_send_thread_cnt );
      printf("g_client_thread_cnt %d\n",g_client_thread_cnt );
      printf("g_num_wh %d\n",g_num_wh );
      printf("g_perc_payment %f\n",g_perc_payment );
      printf("g_wh_update %d\n",g_wh_update );
      printf("g_part_cnt %d\n",g_part_cnt );
      printf("g_node_cnt %d\n",g_node_cnt );
			printf("g_thread_cnt %d\n",g_thread_cnt );
			printf("g_query_intvl %ld\n",g_query_intvl );
			printf("g_prt_lat_distr %d\n",g_prt_lat_distr );
			printf("g_part_alloc %d\n",g_part_alloc );
			printf("g_mem_pad %d\n",g_mem_pad );
			printf("g_perc_multi_part %f\n",g_perc_multi_part );
			printf("g_tup_read_perc %f\n",g_tup_read_perc );
			printf("g_tup_write_perc %f\n",g_tup_write_perc );
			printf("g_txn_read_perc %f\n",g_txn_read_perc );
			printf("g_txn_write_perc %f\n",g_txn_write_perc );
			printf("g_synth_table_size %ld\n",g_synth_table_size );
			printf("g_field_per_tuple %d\n",g_field_per_tuple );
      printf("g_data_perc %f\n",g_access_perc);
      printf("g_access_perc %f\n",g_access_perc);

    // Initialize client-specific globals
    if (g_node_id >= g_node_cnt)
        init_client_globals();
}
