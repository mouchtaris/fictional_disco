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

  def resolve_saga(saga, io)
    saga.each do |sag|
      sag.call io
    end
  end

  def rewrite!
    file_header_saga = @source_details.file_header_saga
    file_footer_saga = @source_details.file_footer_saga

    preserve_start = file_header_saga.size
    preserve_end = -file_footer_saga.size - 1
    preserve_range = preserve_start..preserve_end

    preserve =
      if preserve_start > @lines.size || preserve_end > @lines.size
        [] of String
      else
        @lines[preserve_range]
      end

    open_w do |fout|
      resolve_saga file_header_saga, fout
      preserve.each { |l| fout.puts l }
      resolve_saga file_footer_saga, fout
    end
  end
end
