class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)

        val recyclerView = binding.recyclerView
        recyclerView.layoutManager = LinearLayoutManager(this)

        val adapter = MyAdapter()
        recyclerView.adapter = adapter

        val data = listOf(
            MyData("Item 1", "Description 1"),
            MyData("Item 2", "Description 2"),
            MyData("Item 3", "Description 3"),
            MyData("Item 4", "Description 4"),
            MyData("Item 5", "Description 5")
        )

        adapter.submitList(data)

        val button = binding.button
        button.setOnClickListener {
            val dialog = AlertDialog.Builder(this)
                .setTitle("Dialog Title")
                .setMessage("Dialog Message")
                .setPositiveButton("OK") { dialogInterface, i ->
                    dialogInterface.dismiss()
                }
                .create()
            dialog.show()
        }
    }

    data class MyData(val title: String, val description: String)

    class MyAdapter : RecyclerView.Adapter<MyAdapter.ViewHolder>() {

        private var data = listOf<MyData>()

        override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
            val view = LayoutInflater.from(parent.context).inflate(R.layout.item, parent, false)
            return ViewHolder(view)
        }

        override fun onBindViewHolder(holder: ViewHolder, position: Int) {
            val item = data[position]
            holder.itemView.findViewById<TextView>(R.id.text_view).text = item.title
            holder.itemView.findViewById<TextView>(R.id.description_view).text = item.description
        }

        override fun getItemCount(): Int {
            return data.size
        }

        fun submitList(data: List<MyData>) {
            this.data = data
            notifyDataSetChanged()
        }

        class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)
    }
}


interface MyInterface {
    fun myFunction()
}
