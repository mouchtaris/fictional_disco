# vim: et ts=2 sw=2

module Source
  include ConfDirViews  # conf_*
  include FileViews  # @lines
  @source_details : SourceDetails

  def open_w
    File.open(@source_details.path, "w") do |fout|
      yield fout
    end
  end

  def header_generated_lines_count
    header_saga.size
  end

  def resolve_saga(saga, io)
    saga.each do |sag|
      sag.call io
    end
  end

  def rewrite!
    header_saga_ = header_saga
    footer_saga_ = footer_saga

    preserve_start = header_saga_.size
    preserve_end = -footer_saga_.size - 1
    preserve_range = preserve_start..preserve_end

    preserve =
      if preserve_start > @lines.size || preserve_end > @lines.size
        [] of String
      else
        @lines[preserve_range]
      end

    open_w do |fout|
      resolve_saga header_saga_, fout
      preserve.each { |l| fout.puts l }
      resolve_saga footer_saga_, fout
    end
  end
end
